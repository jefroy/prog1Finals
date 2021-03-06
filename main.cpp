// main.cpp
#include "util.h"
#include "menu.h"

int option10(double *opens, double *entries, double *disparities, int numEntries);

using namespace std;

int main () {
    double open_prices[MAX_OPEN_PRICES]; // from input file
    double entries[MAX_ENTRIES]; // for user entries
    int search_results[MAX_SEARCH_RESULTS]; // for search
    double disparities[MAX_DISPARITIES]; // all disparities

    resetSearches(search_results); // initialize array
    resetEntries(entries); // initialize array

    int numEntries = 0;
    int choice = -1;

    int isOpenPrices = populateArrayFromFile(open_prices);

    if(isOpenPrices > 0){
        populateDisparities(open_prices, disparities);
        while (choice != OPTION_QUIT){
            choice = menu();
            if (choice == OPTION_HIGHEST_OPEN){
                option1(open_prices, MAX_OPEN_PRICES);
            } else if(choice == OPTION_LOWEST_OPEN){
                option2(open_prices, MAX_OPEN_PRICES);
            } else if(choice == OPTION_AVG_OPEN){
                option3(open_prices);
            } else if(choice == OPTION_HIGHEST_DISPARITY){
                option4(disparities, MAX_DISPARITIES);
            } else if(choice == OPTION_LOWEST_DISPARITY){
                option5(disparities, MAX_DISPARITIES);
            } else if(choice == OPTION_GRAPH){
                option6(disparities, MAX_DISPARITIES);
            } else if(choice == OPTION_SEARCH){
                option7(open_prices, MAX_OPEN_PRICES, search_results);
            } else if(choice == OPTION_UPDATE){
                option8(MAX_OPEN_PRICES, search_results, disparities, open_prices);
            } else if (choice == OPTION_ADD_ENTRY){
                numEntries = option9(entries);
            } else if (choice == OPTION_SAVE){
                option10(open_prices, entries, disparities, numEntries);
            }
        }

    }

    return 0;
}
