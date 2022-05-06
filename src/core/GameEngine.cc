#include "GameEngine.h"

namespace space_invader_game {
GameEngine::GameEngine() {
    player(Location(10,50)),
    move_player{Movement::kStop},
    move_player_projectile{Movement::kStop},
    move_invader_projectile{Movement::kShoot},
    move_nyan_cat{Movement::kStop},
    player_projectile_ = new Projectile(player.GetLocation());
}

InvaderManager GameEngine::GetWaveInvader() const {
    return wave_invader_;
}
Player GameEngine::GetPlayer() const {
    return player_;
}
Projectile* GameEngine::GetPlayerProjectile() const {
    return player_projectile_;
}
Projectile* GameEngine::GetInvaderProjectile() const; {
    return invader_projectile_;
}

void GameEngine::SetUpWave() {
    for (int i = 0; i < kNumberOfRows; i++) {
        for (int j = 0; j < kNumberOfCols; j++) {
            Location location(j * kNumberOfCols, i * kNumberOfCols + kNumberOfCols);
            wave_invader_.FillWave(Invader(location));
        }
    }
    Location scaled(wave_invader_.GetInvader(2, 1).GetLocation().Row() + 1,
                    wave_invader_.GetInvader(2, 1).GetLocation().Col() + 2);
    invader_projectile_ = new Projectile(scaled);
}

Location GameEngine::GetInitialInvaderPosition(int num_Count) {
    Location loc(0,0);
    int count = 0;

    for (int i = 0; i < kNumberOfRows; i++) {
        for (int j = 0; j < kNumberOfCols; j++) {
            if (count == num_Count) {
                Location initial(j * kNumberOfCols,
                                 i * kNumberOfCols + kNumberOfCols);
                loc = initial;
            }
            count++;
        }
    }
    return loc;
}


void GameEngine::NextWave() {
    int position_count = 0;
    for (Invader& invader : wave_invader_) {
        invader.SetAlive(true);
        invader.SetLocation(GetInitialInvaderPosition(position_count));
        position_count++;
    }
}

void GameEngine::ResetGame() {
    int position_count = 0;

    for (Invader& invader : wave_invader_) {
        invader.SetAlive(true);
        invader.SetLocation(GetInitialInvaderPosition(position_count));
        position_count++;
    }

    if (score > high_score) {
        high_score = score;
    }

    score = 0;

    player.SetAlive(true);
}

int GameEngine::GetScore() const {
    return score;
}

int GameEngine::GetHighScore() const {
    return high_score;
}

void GameEngine::SetProjectileDirection(Movement move) {
    move_player_projectile = move;
}

void GameEngine::InvaderMove() {
    for (Invader& invader : wave_invader_) {
        Location invader_location = (invader.GetLocation() + MoveInvaderWave(toRight, distance_to_border));
        invader.SetLocation(invader_location);

        if (invader.GetLocation().Col() == player.GetLocation().Col()
            && invader.IsAlive()) {
            player.SetAlive(false);
        }
    }
    distance_to_border++;
    if (distance_to_border == kDistanceToOppositeBorder) {
        toRight = !toRight;
        distance_to_border = 0;
    }
}

void GameEngine::PlayerMove() {
    Location player_location = MovePlayer();
    Location new_player_location = (player.GetLocation() + player_location) % Location(kDimension, kDimension);
    player.SetLocation(new_player_location);

    if (move_player_projectile != Movement::kShoot) {
        Location scaled(player.GetLocation().Row() + 1, player.GetLocation().Col());
        player_projectile_->SetLocation(scaled);
    }
}

void GameEngine::PlayerProjectile() {
    if (move_player_projectile == Movement::kShoot) {
        player_projectile_->SetAlive(true);
        Location projectile_location = MoveProjectile();
        Location new_projectile_loc =
                (player_projectile->GetLocation() + projectile_location);
        player_projectile_->SetLocation(new_projectile_loc);
        projectile_distance++;
        for (Invader& invader : wave_invader_) {
            Location invader_hitbox_1(invader.GetLocation().Row() + 1,
                                      invader.GetLocation().Col() + 1);
            Location invader_hitbox_2(invader.GetLocation().Row() + 2,
                                      invader.GetLocation().Col() + 1);
            if ((invader.GetLocation() == player_projectile_->GetLocation()
                 || invader_hitbox_1 == player_projectile_->GetLocation()
                 || invader_hitbox_2 == player_projectile_->GetLocation())
                && invader.IsAlive()) {
                score += 10;
                invader.SetAlive(false);
                player_projectile_->SetAlive(false);
                delete player_projectile_;
                Projectile* new_projectile = new Projectile(player.GetLocation());
                player_projectile_ = new_projectile;
                action_player_projectile = Action::kReload;
                projectile_distance = 0;
            }
        }
        if (projectile_distance == kDimension) {
            player_projectile_->SetAlive(false);
            delete player_projectile_;
            Projectile* new_projectile = new Projectile(player.GetLocation());
            player_projectile_ = new_projectile;
            action_player_projectile = Action::kReload;
            projectile_distance = 0;
        }
    }
}

void GameEngine::InvaderProjectile() {
    Location projectile_location = MoveInvaderProjectile();
    Location new_projectile_loc = (invader_projectile->GetLocation() + projectile_location);

    Location player_hitbox_1(player.GetLocation().Row() + 1, player.GetLocation().Col());

    Location player_hitbox_2(player.GetLocation().Row() + 2, player.GetLocation().Col());

    invader_projectile_->SetLocation(new_projectile_loc);

    if (invader_projectile_->GetLocation() == player.GetLocation()
        || invader_projectile_->GetLocation() == player_hitbox_1
        || invader_projectile_->GetLocation() == player_hitbox_2) {
        player.SetAlive(false);
    }
    invader_projectile_distance++;
    if (invader_projectile_distance == kDimension) {
        int random_int = std::rand() % kNumberOfCols;
        int shoot_row = kNumberOfRows - 1;
        for (int i = 0; i < kNumberOfRows; i++) {
            if (wave_invader_.GetInvader(shoot_row, random_int).IsAlive() == false) {
                shoot_row--;
            }
        }
        invader_projectile_distance = 12;
        if (shoot_row != -1) {
            delete invader_projectile;
            Projectile* new_invader_projectile = new Projectile(
                    wave_invader_.GetInvader(shoot_row, random_int).GetLocation());
            Location scaled(new_invader_projectile->GetLocation().Row() + 1,
                            new_invader_projectile->GetLocation().Col() + 2);
            new_invader_projectile->SetLocation(scaled);
            invader_projectile = new_invader_projectile;
            invader_projectile_distance = 0;
        }
    }
}

Location GameEngine::MoveInvaderWave(bool toRight, int distance_to_border) {
    if (toRight == false && distance_to_border != 0) {
        return {-1, 0}
    } else if (toRight == false && distance_to_border == 0) {
        return {0, +1};
    } else if (toRight == true && distance_to_border == 0) {
        return {0, +1};
    }
    return {+1, 0};
}

Location GameEngine::MovePlayer() {
    if (move_player == Movement::kLeft) {
        return {-1, 0};
    } else if (move_player == Movement::kRight) {
        return {+1, 0};
    }
    return {0,0};
}

Location GameEngine::MoveProjectile() {
    if (move_player_projectile == Movement::kShoot) {
        return {0, -1};
    }
    return {0, 0};
}
Location GameEngine::MoveInvaderProjectile() {
    return {0, +1};
}

} //namespace space_invader_game
