const int numAttributes = 3;
const int numExamples = 4;
const char* trainingData[numExamples][numAttributes] = {
    {"eat", "play", "fetch"},
    {"eat", "play", "fetch"},
    {"neat", "nplay", "fetch"},
    {"eat", "play", "nfetch"}
};
const bool isPositive[numExamples] = {true, true, false, true};
char hypothesis[numAttributes][10];
char inputHypothesis[numAttributes][10] = { "neat", "play", "fetch" }; // Example input hypothesis

void initializeHypothesis() {
    for (int i = 0; i < numAttributes; i++) {
        strcpy(hypothesis[i], "0");
    }
}

void findS() {
    initializeHypothesis();
    for (int i = 0; i < numExamples; i++) {
        if (isPositive[i]) {
            for (int j = 0; j < numAttributes; j++) {
                if (strcmp(hypothesis[j], "0") == 0) {
                    strcpy(hypothesis[j], trainingData[i][j]);
                } else if (strcmp(hypothesis[j], trainingData[i][j]) != 0) {
                    strcpy(hypothesis[j], "?");
                }
            }
        }
    }
}

bool compareHypotheses(const char inputHypothesis[][10], const char hypothesis[][10], int numAttributes) {
    for (int i = 0; i < numAttributes; i++) {
        if (strcmp(inputHypothesis[i], hypothesis[i]) != 0 && strcmp(hypothesis[i], "?") != 0) {
            return false;
        }
    }
    return true;
}


void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ; // Wait for serial port to connect. Needed for native USB port only
    }

    findS();
    Serial.println("\nThe final hypothesis is:");
    for (int i = 0; i < numAttributes; i++) {
        Serial.print(hypothesis[i]);
        Serial.print(" ");
    }
    Serial.println();

    bool result = compareHypotheses(inputHypothesis, hypothesis, numAttributes);
    Serial.println(result ? "Input hypothesis is true." : "Input hypothesis is false.");
}

void loop() {
    // Nothing to do here
}

