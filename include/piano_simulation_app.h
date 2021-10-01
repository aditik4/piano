
#ifndef FINAL_PROJECT_ADITIK4_PIANO_SIMULATION_APP_H
#define FINAL_PROJECT_ADITIK4_PIANO_SIMULATION_APP_H

#include "Keyboard.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Score.h"

namespace piano {
class PianoSimulationApp : public ci::app::App {
public:
    /**
     * Constructs a simulation object.
     */
    PianoSimulationApp();
    /**
     * Handles the display of simulation.
     */
    void draw() override;
    /**
     * The window size of the simulation.
     */
    const int kWindowSize = 700;
    /**
     * Handles playing notes when certain keys are pressed
     * @param event the key being pressed.
     */
    void keyDown(cinder::app::KeyEvent event) override;

private:
    /**
     * The keyboard or set of keys belonging to this piano.
     */
    Keyboard keyboard_;
    /**
     * The score that will display notes on staff as they are
     * played by the user.
     */
    Score score_;
    /**
     * Stores the background color of the screen
     */
    cinder::ColorT<float> kBackgroundColor = "black";
};
}


#endif //FINAL_PROJECT_ADITIK4_PIANO_SIMULATION_APP_H
