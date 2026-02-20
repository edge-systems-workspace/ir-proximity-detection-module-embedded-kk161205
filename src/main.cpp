#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Obstacle Detection System using IR Sensor
 * @author kk161205
 * @date 2026-02-20
 *
 * @details
 * Reads digital input from IR sensor
 * and detects obstacle presence.
 */

/* ===========================
   Global Definitions
   =========================== */

/** @brief Digital pin connected to IR sensor OUT */
const uint8_t IR_PIN = 2;

/** @brief Variable to store IR sensor state */
uint8_t irState = HIGH;

/**
 * @brief Arduino setup function
 *
 * Initializes serial communication,
 * configures IR sensor pin, and prints
 * system startup message.
 */
void setup() {

    Serial.begin(9600);

    while (!Serial) {
        ; // Recommended for Uno R4
    }

    pinMode(IR_PIN, INPUT);

    Serial.println("=================================");
    Serial.println(" Embedded Obstacle Detection System ");
    Serial.println(" IR Sensor Initialized ");
    Serial.println("=================================");
}

/**
 * @brief Arduino main execution loop
 *
 * Reads digital IR sensor state and processes detection logic.
 */
void loop() {

    irState = digitalRead(IR_PIN);

    if (irState == LOW) {
        Serial.println("Obstacle Detected");
    } else {
        Serial.println("No Obstacle");
    }
}