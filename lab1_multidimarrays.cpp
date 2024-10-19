#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

class Spreadsheet{
    private:
        int data[ROWS][COLS];
    
    public:
        Spreadsheet(){
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLS; j++){
                    data[i][j] = 0;
                }
            }
        }

        void inputCellData(int row, int col){ // only inputs for one cell data
            cout << "Enter value for cell (" << row << ", " << col << "): ";
            cin >> data[row][col];

        }

        void inputData(){ // inputs data for the entire spreadsheet
            cout << "Enter values for the spreadsheet (5 rows and 5 columns):\n";
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLS; j++){
                    inputCellData(i,j); // in nested loop to go through all of the cells and inputs data by user
                }
            }

        }

        void display(){ // displays the spreadsheet data
            cout << "Spreadsheet Data:" << endl;
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLS; j++){
                    cout << data[i][j] << "\t";
                }
                cout << endl;
            }
        }

        void calculateSumsAndAverages(){ // calculates sums and averages for BOTH rows and columns
            for(int i = 0; i < ROWS; i++){ // for rows' sum and average
                int rowSum = 0;
                for(int j = 0; j < COLS; j++){
                    rowSum += data[i][j];
                }
                double rowAverage = rowSum/5.0; // calculates rowAverage
                cout << "Row " << i << " - Sum: " << rowSum << ", Average: " << rowAverage << endl; // prints out rowSum and rowAverage
            }

            for(int j = 0; j < COLS; j++){ // for columns' sum and average
                int colSum = 0;
                for(int i = 0; i < ROWS; i++){
                    colSum = data[i][j];
                }
                double colAverage = colSum / 5.0; // calculates colAverage
                cout << "Column " << j << " - Sum: " << colSum << ", Average: " << colAverage << endl; // prints out colSum and colAverage
            }
        }

        void findMaxMin(){ // finds both the maximum and minimum value
            if(ROWS == 0 || COLS == 0){
                cout << "Spreadsheet is empty." << endl; // checks if the spreadsheet is empty
                return;
            }
            int maxVal = data[0][0];
            int minVal = data[0][0];

            for(int i = 0; i < ROWS; i++){ // for loop to compare the values with current minVal/maxVal
                for(int j = 0; j < COLS; j++){
                    if(data[i][j] > maxVal){
                        maxVal = data[i][j];
                    }
                    if(data[i][j] < minVal){
                        minVal = data[i][j];
                    }
                }
            }
            cout << "Maximum Value: " << maxVal << endl; // prints out maximum value
            cout << "Minimum Value: " << minVal << endl; // prints out minimum value
        }

        void searchValue(int value){
            cout << "Enter value to search for: "; 
            cin >> value;
            
            bool found = false; // only true when value is found in the spreadsheet
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLS; j++){
                    if(data[i][j] == value){
                        cout << "Value " << value << " found at cell (" << i << ", " << j << ")" << endl;
                        found = true;
                    }
                }
            }
            if(!found){
                cout << "Value was not found in spreadsheet." << endl;
            }
        }
};

        int main(){
            Spreadsheet spreadsheet;

            spreadsheet.inputData(); // input cell data in spreadsheet

            int row; int col;
            
            int choice; // utilized for menu input and navigating through the menu
            do{
                cout << "\nMenu:\n";
                cout << "1) Input individual cell data\n";
                cout << "2) Display Data\n";
                cout << "3) Calculate Row and Column Sum And Averages\n";
                cout << "4) Search for a value\n";
                cout << "5) Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch(choice){ // choice corresponds to the function
                    case 1:
                        cout << "Cell ";
                        cin >> row >> col;
                        spreadsheet.inputCellData(row, col);
                        break;
                    case 2:
                        spreadsheet.display();
                        break;
                    case 3:
                        spreadsheet.calculateSumsAndAverages();
                        break;
                    case 4:
                        int searchValue;
                        spreadsheet.searchValue(searchValue);
                        break;
                    case 5:
                        cout << "Exiting program." << endl;
                        break;
                    default:
                        cout << "Invalid choice, please try again." << endl;
                }
            } while(choice != 5);

            return 0;

        }
