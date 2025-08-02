//
// Created by Pernea Alex on 02.08.2025.
//

#include "PluginEditor.h"
#include "PluginProcessor.h"

Bap1AudioProcessorEditor::Bap1AudioProcessorEditor(Bap1AudioProcessor& p)
    : AudioProcessorEditor (&p), bap1_audio_processor (p)
{
    setSize(800, 800);
}

Bap1AudioProcessorEditor::~Bap1AudioProcessorEditor() = default;

void Bap1AudioProcessorEditor::paint(juce::Graphics &g) {
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void Bap1AudioProcessorEditor::resized() {}