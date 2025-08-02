//
// Created by Pernea Alex on 02.08.2025.
//

#pragma once

#ifndef PLUGINPROCESSOR_H
#define PLUGINPROCESSOR_H

#include <juce_audio_processors/juce_audio_processors.h>

class Bap1AudioProcessor : public juce::AudioProcessor{
public:
    Bap1AudioProcessor();
    ~Bap1AudioProcessor() override;

    void prepareToPlay(double sampleRate, int maximumExpectedSamplesPerBlock) override;
    void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported(const BusesLayout &) const override;
#endif

    void processBlock(juce::AudioBuffer<float> &buffer, juce::MidiBuffer &midiMessages) override;

    //==================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    //==================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String &newName) override;

    //==================================================
    void getStateInformation(juce::MemoryBlock &destData) override;
    void setStateInformation(const void *data, int sizeInBytes) override;

private:
    juce::AudioProcessorValueTreeState parameters;
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Bap1AudioProcessor);

};

#endif //PLUGINPROCESSOR_H
