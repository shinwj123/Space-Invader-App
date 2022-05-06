#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "my_app.h"


using cinder::app::App;
using cinder::app::RendererGl;


namespace myapp {

    const int kSamples = 8;

//Number of tiles in a row/col
    const int kDimension = 48;
    const int kTileSize = 50/3;

    const int kWidth = static_cast<int>(kDimension * kTileSize);
    const int kHeight = static_cast<int>(kDimension * kTileSize);

    void SetUp(App::Settings* settings) {
        settings->setWindowSize(kWidth, kHeight);
        settings->setTitle("Space Invader");
    }

}  // namespace myapp


CINDER_APP(myapp::MyApp,
        RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
        myapp::SetUp)

