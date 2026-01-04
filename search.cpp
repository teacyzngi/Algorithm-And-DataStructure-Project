#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream> // To build the output string

using namespace std;

// Data Structure (unchanged)
struct PatientRecord {
    string patientID;
    int heartRate;
    double spo2;
    double temperature;
};

/**
 * Uses linear search to iterate through all records and find patients with critical vitals.
 * Returns a string summarizing all critical patients found.
 */
string findCriticalVitals(const vector<PatientRecord>& records) {
    string criticalReport = "";
    bool criticalCaseFound = false;

    // Iterate through each patient record (Linear Search)
    for (const auto& patient : records) {
        bool isCritical = false;
        stringstream abnormalValues;

        // Check for critical vitals criteria:
        // 1. Heart rate > 120 bpm
        if (patient.heartRate > 120) {
            isCritical = true;
            abnormalValues << "HR: " << patient.heartRate << " bpm ";
        }

        // 2. SpO₂ < 90%
        if (patient.spo2 < 90.0) {
            isCritical = true;
            abnormalValues << "SpO2: " << fixed << setprecision(0) << patient.spo2 << "% ";
        }

        // 3. Temperature > 39°C
        if (patient.temperature > 39.0) {
            isCritical = true;
            // Ensure temperature is printed with minimal formatting but correctly
            abnormalValues << "Temp: " << fixed << setprecision(1) << patient.temperature << "°C";
        }

        // Build the final output string for critical cases
        if (isCritical) {
            criticalCaseFound = true;
            
            // Format output exactly as requested: Critical patients:Patient P002 - ...
            criticalReport += "Patient " + patient.patientID + " - " + abnormalValues.str();
        }
    }

    if (!criticalCaseFound) {
        return "All patients are stable"; // Requirement 7
    } else {
        // We prepend the required header and clean up multiple entries if needed
        return "Critical patients:" + criticalReport;
    }
}

// --- Main Program with User Input ---
int main() {
    int numPatients;

    cout << "Enter number of patients: ";
    // Accept input for the number of patients
    if (!(cin >> numPatients) || numPatients < 0) {
        cerr << "Invalid number of patients." << endl;
        return 1;
    }

    vector<PatientRecord> patientList;
    cout << "Enter patient data (ID HR SpO2 Temp) line by line:" << endl;

    // Loop to collect data for N patients
    for (int i = 0; i < numPatients; ++i) {
        PatientRecord patient;
        
        // Accept input for ID, HR, SpO2, and Temp on one line
        if (cin >> patient.patientID >> patient.heartRate >> patient.spo2 >> patient.temperature) {
            patientList.push_back(patient);
        } else {
            cerr << "Input reading error for patient " << i + 1 << ". Exiting." << endl;
            return 1;
        }
    }

    // Process and print the result
    string result = findCriticalVitals(patientList);
    cout << "\nOutput:\n" << result << endl;

    return 0;
}