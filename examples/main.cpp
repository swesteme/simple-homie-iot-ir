#include <Arduino.h>
#include <KillConfigNode.h>
#include <IrReceiver.h>
#include <IrRemoteButton.h>
#include <Switch.h>

// Homie node receiving the signal to kill the Homie configuration and reboot.
KillConfigNode killConfigNode;

// Infrared receiver
IrReceiver irReceiver(D3, "Infrared-sensor");

// Convenience button instances.
IrRemoteButton buttonSource(&irReceiver, "btnSource", "Source Button",
                            1086277815);
IrRemoteButton buttonPlay(&irReceiver, "btnPlay", "Play Button", 1086281895);
IrRemoteButton buttonLamp(&irReceiver, "btnLamp", "Lamp Button", 1086290055);
IrRemoteButton buttonBack(&irReceiver, "btnBack", "Back Button", 1086275775);
IrRemoteButton buttonSkip(&irReceiver, "btnSkip", "Skip Button", 1086308415);
IrRemoteButton buttonFmMode(&irReceiver, "btnFmMode", "FmMode Button",
                            1086267615);
IrRemoteButton buttonMute(&irReceiver, "btnMute", "Mute Button", 1086316575);
IrRemoteButton buttonPresetPlus(&irReceiver, "btnPresetPlus",
                                "PresetPlus Button", 1086300255);
IrRemoteButton buttonPresetMinus(&irReceiver, "btnPresetMinus",
                                 "PresetMinus Button", 1086263535);
IrRemoteButton buttonVolumePlus(&irReceiver, "btnVolumePlus",
                                "VolumePlus Button", 1086283935);
IrRemoteButton buttonVolumeMinus(&irReceiver, "btnVolumeMinus",
                                 "VolumeMinus Button", 1086296175);

void setup() {
  Serial.begin(115200);
  Serial << endl << "Start setup..." << endl;

  // inititalise Homie library
  Homie_setFirmware("livingroom", "1.0.0");
  Homie.setup();

  Serial << "Finished setup." << endl;
}

void loop() {
  // run homie loop
  Homie.loop();
}
