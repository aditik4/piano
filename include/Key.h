
#ifndef FINAL_PROJECT_ADITIK4_KEY_H
#define FINAL_PROJECT_ADITIK4_KEY_H
#include <string>
#include "cinder/gl/gl.h"
#include "cinder/audio/Voice.h"
using glm::vec2;
namespace  piano {
    class Key {
    public:
        /**
         * Default constructor for key object.
         */
        Key();
        /**
         * Constructs a key with a note, the number of steps away from middle C,
         * a color, and an octave
         * @param note the note name of the key
         * @param numSteps the number of steps away from middle C
         * @param color the color of the key (white or black)
         * @param the octave this key belongs to
         */
        Key(std::string note, double numSteps, cinder::ColorT<float> color, std::string octave);
        /**
         * Plays the given note out loud.
         */
        void PlayNote() const;
        /**
         * Draws out the key given the coordinates
         * @param ax1 the rightmost x coordinate
         * @param ay1 the topmost y coordinate
         * @param ax2 the leftmost x coordinate
         * @param ay2 the bottommost y coordinate
         */
         void DrawKey(vec2 lower, vec2 upper) const;
        /**
         * Loads the audio file for this note
         * code from: https://libcinder.org/docs/guides/audio/index.html#read_audio
         */
        void LoadAudioFile();
        /**
         * Obtains the note letter
         * @return the letter of the note
         */
        std::string GetNote() const;
        /**
         * Obtains upper coordinates for this key
         * @return a vec2 of coordinates
         */
        const vec2 GetUpperKeyCoords() const;
        /**
         * Obtains lower coordinates for this key
         * @return the vec2 of coordinates
         */
        const vec2 GetLowerKeyCoords() const;
        /**
         * Highlights the key the highlight color
         */
        void Highlight() const;
        /**
         * Sets the coordinates of the keys
         * @param lower the lower set of coords
         * @param upper the upper set of coords
         */
        void SetKeyCoords(vec2 lower, vec2 upper);
       /**
        * Holds the number of steps away from C the key is.
        * @return the number of steps
        */
        size_t GetNumStepsFromC() const;
        /**
         * Returns the color of the key
         * @return the color of the key
         */
        cinder::ColorT<float> GetColor() const;
        /**
         * Returns the octave of the key
         * @return the key's octave
         */
        std::string GetOctave() const;
    private:
        /**
         * the letter note of the key
         */
        std::string note_;
        /**
         * the audio object for playing the note file
         */
        cinder::audio::VoiceRef mVoice;
        /**
         * The lower key coordinates of a key's position
         */
        glm::vec2 lowerKeyCoords_;
        /**
         * the upper coordinates of a key's position
         */
        glm::vec2 upperKeyCoords_;
        /**
         * Stores the number of steps away from middle C the note is.
         */
        double numStepsFromC_;
        /**
         * Stores the type of key (ie black or white) in color.
         */
        cinder::ColorT<float> color_;
        /**
         * Stores which octave the note belongs to.
         */
        std::string octave_;
        /**
         * Holds the color of the highlight
         */
        cinder::ColorT<float> kHighlightColor = "cyan";
        /**
         * Stores the color of the note's letter display
         */
        cinder::ColorT<float> kStringColor = "grey";
        /**
         * Stores the corner radius of the key's rectangle
         */
        int kCornerRadius = 6;
        /**
         * Stores the number of segments per corner of key's rectangle
         */
        int kNumSegPerCorner = 1;
    };
}


#endif //FINAL_PROJECT_ADITIK4_KEY_H
