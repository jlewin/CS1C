#include <iostream>
#include <cstring>

using namespace std;

void q73_1();
void painful_shift2();
bool isSymmetric(const int numbersArray[], int arraySize);
int binarySearch(const int list[], int key, int listSize);

  void reverse(const int list[], const int size, int newList[])
  {
    for (int i = 0; i < size; i++)
      newList[i] = list[size - 1 - i];
  }

  void q7_6_4() {
    int list[] = {1, 2, 3, 4, 5};
    int newList[5];
  
    reverse(list, 5, newList);
    for (int i = 0; i < 5; i++)
      cout << newList[i] << " ";
  }

void selectionSort(double list[], int listSize) {
    for (int i = 0; i < listSize - 1; i++) {
        // Find the minimum in the list[i..listSize-1]
        double currentMin = list[i];
        int currentMinIndex = i;

        for (int j = i + 1; j < listSize; j++){
            if (currentMin > list[j]) {
                currentMin = list[j];
                currentMinIndex = j;
            }
        }

        // Swap list[i] with list[currentMinIndex] if necessary;
        if (currentMinIndex != i){
            list[currentMinIndex] = list[i];
            list[i] = currentMin;
        }
    }
}

 int countLetters(const char s[])
 {
   int count = 0;
   for (int i = 0; i < strlen(s); i++)
   {
     if (isalpha(s[i])) count++;
   }

   return count;
 }

void stringOrder(const char text[]) {
    int n = 0;
    int result = 0;

    while (text[n] != '\0') {
        // Convert char to int
        int v = text[n++] - '0';

        // Accumulate if within 0-9, ortherwise exit
        if (v >= 0 && v <= 9) {
            result = result * 10 + v;
        } else {
            break;
        }
    } ;

    cout << result;
}

int maindddd() {
    //q73_1();
    //painful_shift2();
    // int surveyResponses[] = {8 , 2, 9, 24, 201, 3 ,2 };
    // int nResponses = 7;
    //cout << isSymmetric(surveyResponses, nResponses);

    char word1[] = "193BDA";
    stringOrder(word1);

    char cityy[7] = "Dallas"; 
    char cityx[] = "Dallas";

    cout << to_string(1.2) << "Good" << endl;

    return 0;
}

int binarySearch(const int list[], int key, int listSize)
{
    int low = 0;
    int high = listSize - 1;
    
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (key < list[mid])
            high = mid - 1;
        else if (key == list[mid])
            return mid;
        else 
            low = mid + 1;
    }

    return -1; // Not found
}

void printArrayddd(int items[], int len) {
    for (int i = 0; i < len; i++) {
        cout << items[i] << endl;
    }
    cout << endl;
}

void printArray(int list[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << list[i] << " ";
    }
}


void q73_1() {
double myList[] = {1, 5, 5, 5, 5, 1};
double max = myList[0];
int indexOfMax = 0;
for (int i = 1; i < 6; i++) 
{
  if (myList[i] > max) 
  {
    max = myList[i];
    indexOfMax = i;
  }
}
cout << indexOfMax << endl;
}

int main_q72() {

    // /home/codegrade/student/tests.cpp
    int surveyResponses[] = {8 , 2, 9, 24, 201, 3 ,2 };
    int nResponses = 7;

    int smallestResponse = surveyResponses[0];
    int firstIndex = nResponses;
    int lastIndex = 0;
    int occurences = 0;

    for (int i = 1; i < nResponses; i++) {
        if (surveyResponses[i] < smallestResponse) {
            smallestResponse = surveyResponses[i];
        }
    }

    for (int i = 1; i < nResponses; i++) {
        if (surveyResponses[i] == smallestResponse) {
            if (firstIndex > i) {
                firstIndex = i;
            }
            
            if (lastIndex < i) {
                lastIndex = i;
            }
            occurences++;
        }
    }

    return 0;
}
bool isSymmetric(const int numbersArray[], int arraySize) {
    int lastIndex = arraySize - 1;
    int midpoint = arraySize / 2; // Seemingly floor if I recall right
    for(int i = 0; i < midpoint; i++) {
        if (numbersArray[i] != numbersArray[lastIndex - i])
            return false;
    }

    return true;
}

void painful_shift2() {

    int arraySize = 5;
    int numbersArray[] = {1, 2, 3, 4, 5 };

    int shift = 2;

    int initial[arraySize];

    // Copy the initial array
    for (int j = 0; j < arraySize; j++)
    {
        initial[j] = numbersArray[j];
    }

    for (int j = arraySize - 1; j >= 0; j--)
    {
        // Target index with +2 shift
        int n = j + shift;
        // Clamp
        int i = n % arraySize;

        cout << i << " " << n;
        // Swap to clamped index
        numbersArray[i] = initial[j];

        printArray(numbersArray, arraySize);
    }
}



int indexOf(int items[], int len, int val) {
    for (int i = 0; i < len; i++) {
        if (items[i] == val) {
            return i;
        }
    }

    return -1;
}

  void selectionSort(int list[], int listSize)
  {
    for (int i = 0; i < listSize - 1; i++)
    {
      // Find the minimum in the list[i..listSize-1]
      int currentMin = list[i];
      int currentMinIndex = i;
  
      for (int j = i + 1; j < listSize; j++)
      {
        if (currentMin > list[j])
        {
          currentMin = list[j];
          currentMinIndex = j;
        }
      }
  
      // Swap list[i] with list[currentMinIndex] if necessary;
      if (currentMinIndex != i)
      {
        list[currentMinIndex] = list[i];
        list[i] = currentMin;
      }
    }
  }

void increase(int x[], int size)
 {
   for (int i = 0; i < size; i++)
     x[i]++;
 }

 void increase(int y)
 {
   y++;
 }

void transpose_test();

int main() {
    transpose_test();
    return 0;
}

void transpose_test() {
    int n = 3;

    int matrix[3][3] = {
     {1, 2, 3,},
     {4, 5, 6,},
     {7, 8, 9}
   };

    
    int temp = 0;
    for (int r = 0; r < n; r++) {
        for (int c = r + 1; c < n; c++) {
            // Store
            temp = matrix[r][c];
            // Swap
            matrix[r][c] = matrix[c][r];
            // Restore
            matrix[c][r] = temp;

            cout << ".";
        }
    }
    cout << endl;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            // Store
            cout << matrix[r][c] << '\t';
        }
        cout << endl;
    }
}

 int main2n()
 {
   int x[] =
   {
     1, 2, 3, 4, 5
   };

   increase(x, 5);

   int y[] =
   {
     1, 2, 3, 4, 5
   };

   increase(y[0]);

   cout << x[0] << " " << y[0];

   return 0;
 }

int maindddawer() {

    cout << "Enter the numbers between 1 and 100 ending with 0: ";
    int items[100];
    int count = 0;

    int val;

    do
    {
        cin >> val;
        if (val != 0)
        {
            items[count++] = val;
        }
    } while (val != 0);

    selectionSort(items, count);

    int itemCount = 1;
    for (int i = 0; i < count; i+= itemCount) {
        itemCount = 1;
        int current = items[i];

        while (i < count -1 && items[i + itemCount] == current) {
            itemCount += 1;
        }

        cout << current << " occurs " << itemCount << (itemCount == 1 ? " time" : " times") << endl;
    }

    return 0;
}