//
// Created by Pernea Alex on 02.08.2025.
//

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include <juce_audio_processors/juce_audio_processors.h>

Bap1AudioProcessor::Bap1AudioProcessor()
    : AudioProcessor (BusesProperties().withInput ("Input", juce::AudioChannelSet::stereo(), true)
                                     .withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
      parameters(*this, nullptr, "PARAMETERS", createParameterLayout()){}
Bap1AudioProcessor::~Bap1AudioProcessor() = default;

//==================================================
void Bap1AudioProcessor::prepareToPlay(double sampleRate, int maximumExpectedSamplesPerBlock) {}
void Bap1AudioProcessor::releaseResources() {}

bool Bap1AudioProcessor::isBusesLayoutSupported(const BusesLayout & layouts) const {
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::mono()
        || layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

void Bap1AudioProcessor::processBlock(juce::AudioBuffer<float> &buffer, juce::MidiBuffer &midiMessages) {
    juce::ScopedNoDenormals noDenormals;

    if(*parameters.getRawParameterValue("bypass")) return;

    buffer.clear();
}

//==================================================
juce::AudioProcessorEditor *Bap1AudioProcessor::createEditor() {
    return new Bap1AudioProcessorEditor(*this);
}

bool Bap1AudioProcessor::hasEditor() const {
    return true;
}

//==================================================
const juce::String Bap1AudioProcessor::getName() const {
    return JucePlugin_Name;
}
bool Bap1AudioProcessor::acceptsMidi() const {
    #if JucePlugin_WantsMidiInput
        return true;
    #else
        return false;
    #endif
}
bool Bap1AudioProcessor::producesMidi() const {
    #if JucePlugin_ProducesMidiOutput
        return true;
    #else
        return false;
    #endif
}
bool Bap1AudioProcessor::isMidiEffect() const {
    return false;
}
double Bap1AudioProcessor::getTailLengthSeconds() const {
    return 0.0;
}

//==================================================
int Bap1AudioProcessor::getNumPrograms() {
    return 1;
}
int Bap1AudioProcessor::getCurrentProgram() {
    return 0;
}
void Bap1AudioProcessor::setCurrentProgram(int index) {}
const juce::String Bap1AudioProcessor::getProgramName(int index) {
    return {};
}
void Bap1AudioProcessor::changeProgramName(int index, const juce::String &newName) {}

//==================================================
void Bap1AudioProcessor::getStateInformation(juce::MemoryBlock &destData) {
    juce::MemoryOutputStream stream(destData, true);
    parameters.state.writeToStream(stream);
}
void Bap1AudioProcessor::setStateInformation(const void *data, int sizeInBytes) {
    auto state = juce::ValueTree::readFromData(data, sizeInBytes);
    if(state.isValid()) {
        parameters.replaceState(state);
    }
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new Bap1AudioProcessor();
}

juce::AudioProcessorValueTreeState::ParameterLayout Bap1AudioProcessor::createParameterLayout() {
    using namespace juce;

    std::vector<std::unique_ptr<RangedAudioParameter>> params;
    params.push_back(std::make_unique<AudioParameterFloat>("inputGain","Input Gain",
        NormalisableRange<float>(-10.0f, 10.0f,0.01f), 0.0f));
    params.push_back(std::make_unique<AudioParameterFloat>("drive","Drive",
        NormalisableRange<float>(0.0f,1.0f,0.01f),0.5f));
    params.push_back(std::make_unique<AudioParameterChoice>("mode","Mode",
        StringArray{"MPC3000","MPC60","SP1200"},0));
    params.push_back(std::make_unique<AudioParameterChoice>("filter_switch","Filter",
        StringArray{"Sampler","Filter"},0));
    params.push_back(std::make_unique<AudioParameterBool>("oversample","Oversample",
        false));
    params.push_back(std::make_unique<AudioParameterBool>("bypass","Bypass",
        false));

    return {params.begin(), params.end()};
}
