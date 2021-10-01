
#include "Key.h"
#include "cinder/app/App.h"

namespace piano {
    Key::Key() {}

    Key::Key(std::string note, double numSteps, cinder::ColorT<float> color, std::string octave) {
        note_ = note;
        numStepsFromC_ = numSteps;
        color_ = color;
        octave_ = octave;
        LoadAudioFile();
    }

    std::string Key::GetNote() const  {
        return note_;
    }

    const vec2 Key::GetLowerKeyCoords() const {
        return lowerKeyCoords_;
    }

    const vec2 Key::GetUpperKeyCoords() const {
        return upperKeyCoords_;
    }

    size_t Key::GetNumStepsFromC() const{
        return numStepsFromC_;
    }

    std::string Key::GetOctave() const{
        return octave_;
    }

    cinder::ColorT<float> Key::GetColor() const{
        return color_;
    }

    void Key::SetKeyCoords(vec2 lower, vec2 upper) {
        lowerKeyCoords_ = lower;
        upperKeyCoords_ = upper;
    }

    void Key::DrawKey(vec2 lower, vec2 upper) const {
        ci::gl::drawSolidRoundedRect(
                ci::Rectf(lower, upper), kCornerRadius, kNumSegPerCorner);
        ci::gl::drawString(note_,vec2(lower.x + 5, 230), kStringColor);
    }

    void Key::PlayNote() const{
        std::chrono::seconds interval( 1 );
        mVoice->start();
        std::this_thread::sleep_for( interval);
        mVoice->stop();
    }

    void Key::LoadAudioFile() {
        cinder::audio::SourceFileRef sourceFile = cinder::audio::load(cinder::app::loadAsset("piano" + octave_ +"_" + note_ + ".mp3"));
        mVoice = cinder::audio::Voice::create(sourceFile);
    }

     void Key::Highlight() const{
         ci::gl::color(ci::Color(kHighlightColor));
         ci::gl::drawSolidRoundedRect(ci::Rectf(vec2(lowerKeyCoords_.x, lowerKeyCoords_.y + 20), upperKeyCoords_), 6, 1 );
    }
}