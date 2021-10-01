
#include "piano_simulation_app.h"
#include "cinder/app/App.h"

namespace piano {

    PianoSimulationApp::PianoSimulationApp() {
        keyboard_ = Keyboard("0");
        ci::app::setWindowSize(kWindowSize, kWindowSize);
        score_ = Score();
    }

    void PianoSimulationApp::draw() {
        ci::Color background_color(kBackgroundColor);
        ci::gl::clear(background_color);
        keyboard_.Display();
        score_.Display();
    }

    void PianoSimulationApp::keyDown(cinder::app::KeyEvent event)  {
        switch(event.getCode()) {
            case cinder::app::KeyEvent::KEY_c:
                keyboard_.PlayGivenNote("C");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("C"));
                break;
            case cinder::app::KeyEvent::KEY_d:
                keyboard_.PlayGivenNote("D");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("D"));
                break;
            case cinder::app::KeyEvent::KEY_e:
                keyboard_.PlayGivenNote("E");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("E"));
                break;
            case cinder::app::KeyEvent::KEY_f:
                keyboard_.PlayGivenNote("F");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("F"));
                break;
            case cinder::app::KeyEvent::KEY_g:
                keyboard_.PlayGivenNote("G");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("G"));
                break;
            case cinder::app::KeyEvent::KEY_a:
                keyboard_.PlayGivenNote("A");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("A"));
                break;
            case cinder::app::KeyEvent::KEY_b:
                keyboard_.PlayGivenNote("B");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("B"));
                break;
            case cinder::app::KeyEvent::KEY_DELETE:
                score_.ClearScore();
                break;
            case cinder::app::KeyEvent::KEY_1:
                keyboard_.PlayGivenNote("C#");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("C#"));
                break;
            case cinder::app::KeyEvent::KEY_2:
                keyboard_.PlayGivenNote("D#");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("D#"));
                break;
            case cinder::app::KeyEvent::KEY_3:
                keyboard_.PlayGivenNote("F#");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("F#"));
                break;
            case cinder::app::KeyEvent::KEY_4:
                keyboard_.PlayGivenNote("G#");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("G#"));
                break;
            case cinder::app::KeyEvent::KEY_5:
                keyboard_.PlayGivenNote("A#");
                score_.SetNoteToDraw(keyboard_.FindKeyWithLetter("A#"));
                break;
            case cinder::app::KeyEvent::KEY_RIGHT:
                keyboard_ = Keyboard("1");
                break;
            case cinder::app::KeyEvent::KEY_LEFT:
                keyboard_ = Keyboard("0");
                break;
            default:
                break;
        }
    }

}
