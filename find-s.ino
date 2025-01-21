const int numAttributes = 3; //Variable is used to represent number of attributes in hypothesis.
const int numExamples = 4;  //Variable is used to represent number of datasets avaible for dataset.
const char* trainingData[numExamples][numAttributes] = {
    {"eat", "play", "fetch"},
    {"eat", "play", "fetch"},
    {"neat", "nplay", "fetch"},
    {"eat", "play", "nfetch"}
};
const bool isPositive[numExamples] = {true, true, false, true};
char hypothesis[numAttributes][10]; //This variable is used for storing final hypothesis.
char inputHypothesis[numAttributes][10] = { "neat", "play", "fetch" }; // Example input hypothesis used to decide whether PILLI is happy or sad.

void initializeHypothesis() {
    for (int i = 0; i < numAttributes; i++) {
        strcpy(hypothesis[i], "0");
    }
} //This function is used for initalize hypothesis.

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
} // This function is implementation of find-s alogrithm and used for traning machine then stores final hypothesis in hypothesis variable.

bool compareHypotheses(const char inputHypothesis[][10], const char hypothesis[][10], int numAttributes) {
    for (int i = 0; i < numAttributes; i++) {
        if (strcmp(inputHypothesis[i], hypothesis[i]) != 0 && strcmp(hypothesis[i], "?") != 0) {
            return false;
        }
    }
    return true;
} // This function return true or false based upon input hyopthesis variable. 


void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ; // Wait for serial port to connect. Needed for native USB port only
    }

    findS();
    Serial.println("\nThe final hypothesis is:");
    for (int i = 0; i < numAttributes; i++) {   // This loop prints final hypothesis.
        Serial.print(hypothesis[i]);
        Serial.print(" ");
    }
    Serial.println();

    bool result = compareHypotheses(inputHypothesis, hypothesis, numAttributes);
    Serial.println(result ? "Input hypothesis is true." : "Input hypothesis is false."); // This prints whether final hypothesis is true or false.
}

void loop() {
    // Nothing to do here
}

