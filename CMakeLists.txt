cmake_minimum_required(VERSION 3.15)

# Project Name and Version
project(Bap1 VERSION 0.1.0)

# Set path to JUCE
set(JUCE_DIR "${CMAKE_SOURCE_DIR}/JUCE")

# Add JUCE as a subdirectory
add_subdirectory(${JUCE_DIR} JUCE)

# Define the Plugin Target
juce_add_plugin(Bap1
        COMPANY_NAME "YourCompany"
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT FALSE
        NEEDS_MIDI_OUTPUT FALSE
        EDITOR_WANTS_KEYBOARD_FOCUS FALSE
        COPY_PLUGIN_AFTER_BUILD TRUE
        PLUGIN_MANUFACTURER_CODE BpC1
        PLUGIN_CODE Bp01
        FORMATS VST3
        PRODUCT_NAME "Bap1"
)

# Add Your Source Files
target_sources(Bap1 PRIVATE
        Source/Main.cpp
        Source/PluginProcessor.cpp
        Source/PluginProcessor.h
        Source/PluginEditor.cpp
        Source/PluginEditor.h
)

# Link JUCE modules you need
target_link_libraries(Bap1 PRIVATE
        juce::juce_audio_utils
        juce::juce_audio_processors
        juce::juce_dsp
        juce::juce_gui_basics
)
