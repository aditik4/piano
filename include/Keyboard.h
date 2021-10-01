
#ifndef FINAL_PROJECT_ADITIK4_KEYBOARD_H
#define FINAL_PROJECT_ADITIK4_KEYBOARD_H

#include "Key.h"
#include "cinder/gl/gl.h"


namespace piano {
    class Keyboard {
    public:
        /**
         * Default constructor for keyboard object
         */
        Keyboard();
        /**
         * Constructs a Keyboard with given octave notes
         * @param octave the set of notes on the keyboard.
         */
        Keyboard(std::string octave);
        /**
         * Sets all position values of keys and draws the keyboard on the screen
         */
        void Display() ;
        /**
         * Obtains keys in keyboard.
         * @return the vector of keys
         */
        const std::map<std::string, Key> GetKeys() const;
        /**
         * Plays a certain note aloud
         * @param letter the note to play
         */
        void PlayGivenNote(std::string letter);
        /**
         * Highlights most recent played key.
         */
        bool UpdateHighlight() const;
        /**
         * Obtains the octave of the keyboard.
         */
        int GetOctave() const;
        /**
         * Draws all keys on keyboard.
         */
        void DrawAllKeys();
        /**
         * Finds the key given the letter
         * @return the key with the given letter
         */
        Key& FindKeyWithLetter(std::string letter);
        /**
         * Obtains the most recent played key
         * @return the recent key
         */
         Key& GetRecentPlayedKey();
    private:
        /**
         * The set of keys/notes on this keyboard
         */
        std::map<std::string, Key> key_map_;
        /**
         * Holds the value of key played last
         */
        Key recentPlayedKey_;
        /**
         * Stores the octave of the keyboard.
         */
        std::string octave_;
        /**
         * Holds the lower position of the C key
         */
        vec2 kCKeyLowerPos = vec2(20, 150);
        /**
         * Holds the upper positions of the C key
         */
        vec2 kCKeyUpperPos = vec2(50, 300);
        /**
         * Holds the lower position of the keyboard top
         */
        vec2 kKeyboardTopLowerPos = vec2(20, 150);
        /**
         * Holds the upper position of the keyboard top
         */
        vec2 kKeyboardTopUpperPos = vec2(390, 170);
        /**
         * Stores the color of the keyboard top
         */
        cinder::ColorT<float> kKeyboardTopColor = "purple";
        /**
         * Stores the gap between the keys when drawn
         */
        size_t kGapBetweenKeys = 30;
    };
}


#endif //FINAL_PROJECT_ADITIK4_KEYBOARD_H
