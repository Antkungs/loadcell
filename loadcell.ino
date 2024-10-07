#include "HX711.h"

// Define the pins connected to the HX711
const int LOADCELL_DOUT_PIN = 2; // Data pin
const int LOADCELL_SCK_PIN = 3;  // Clock pin

// Define the calibration factor. Replace this with your own calibration factor.
const float CALIBRATION_FACTOR = 752.777; // Example value; you need to calibrate

HX711 scale;

void setup() {
  Serial.begin(115200);
  
  // Initialize the HX711
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  
  // Perform a tare operation to zero the scale
  scale.tare(); 
  
  // Set the scale factor to calibrate the sensor
  scale.set_scale(CALIBRATION_FACTOR); // Set your calibration factor
}

void loop() {
  if (scale.is_ready()) {
    // Read the weight value
    float weight = scale.get_units(20); // Average of 20 readings
    Serial.println(weight, 2); // Print weight with 2 decimal places
  } else {
    Serial.println("HX711 not found.");
  }
  
  delay(500); // Wait for 1 second
}
