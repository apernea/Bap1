#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include "PluginProcessor.h"

class Bap1AudioProcessorEditor : public juce::AudioProcessorEditor {
public:
    explicit Bap1AudioProcessorEditor(Bap1AudioProcessor &);
    ~Bap1AudioProcessorEditor() override;

    void paint(juce::Graphics &g) override;
    void resized() override;
private:
    Bap1AudioProcessor& bap1_audio_processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Bap1AudioProcessorEditor);
};

