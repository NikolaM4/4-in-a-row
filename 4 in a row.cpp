#include <iostream>

using namespace std;

int main() {
    int n;
    do{
        cout << "Enter number of rows: ";
        cin >> n;
    }
    while(n < 5 || n > 20);
    int arr[n][n];
    int counter = n * n;
    int c = 0;
    int x, y = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = 0;

    while (counter > 0){
        x = 0;
        y = 0;
        cout << "Enter coordinates\n";
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        while (arr[x][y] != 0 || x < 0 || y < 0 || (arr[x+1][y] == 0 && x < n-1) || x > n - 1 || y > n - 1 )
        {
            cout << "Error. Enter new coordinates\n";
            cout << "x: ";
            cin >> x;
            cout << "y: ";
            cin >> y;
        }

        if(c % 2 == 0)
            arr[x][y] = 1;
        else
            arr[x][y] = 2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << '[' << arr[i][j] << "] ";
            cout << "\n";
        }

        if(c % 2 == 0)
        {
            for(int i = 0; i < n; i++){
                sum1 = 0;
                for (int j = 0; j < n; j++)
                {
                    if(arr[i][j] == 1)
                    {
                        sum1++;
                        if (sum1 == 4){
                            cout << "Player 1 win!";
                            return 0;
                        }
                    }
                    else{
                        sum1=0;
                    }
                }
            }
            
            for(int i = 0; i < n; i++){
                sum2=0;
                for (int j = 0; j < n; j++)
                {
                    if(arr[j][i] == 1){
                        sum2++;
                        if(sum2 == 4){
                            cout << "Player 1 win!";
                            return 0;
                        }
                    }
                    else{
                        sum2 = 0;
                    }
                }
            }
            
            for(int i = 0; i < n-3; i++)
            {
                sum3 = 0;
                for(int j = 0; j < n; j++){
                    if(arr[j+i][j] == 1 && (j+i) < n){
                        sum3++;
                    }
                }
                if (sum3 == 4) {
                    cout << "Player 1 win!";
                    return 0;
                }
            }

            for(int i = 0; i < n - 3; i++){
                sum3 = 0;
                for(int j = 0; j < n; j++){
                    if(arr[j][j+i] == 1 && (j+i) < n){
                        sum3++;
                    }
                }
                if (sum3 == 4) {
                    cout << "Player 1 win!";
                    return 0;
                }
            }
            
            for (int i = 0; i < n - 3; i++) {
                sum3 = 0;
                for (int j = 0; j < n; j++) {
                    if (arr[j + i][j] == 1 && (j + i) < n) {
                        sum3++;
                    }
                }
                if (sum3 == 4) {
                    cout << "Player 1 win!";
                    return 0;
                }
            }
            
            for (int i = n - 1; i >= 3; i--) {
                sum3 = 0;
                for (int j = 0; j < n; j++) {
                    if (arr[j][i - j] == 1 && (i - j) >= 0) {
                        sum3++;
                    }
                }
                if (sum3 == 4) {
                    cout << "Player 1 win!";
                    return 0;
                }
            }
        }
        
        if(c % 2 == 1)
        {
            for(int i = 0; i < n; i++){
                sum1 = 0;
                for (int j = 0; j < n; j++)
                {
                    if(arr[i][j] == 2)
                    {
                        sum1++;
                        if (sum1 == 4){
                            cout << "Player 2 win!";
                            return 0;
                        }
                    }
                    else{
                        sum1=0;
                    }
                }
            }
            
            for(int i = 0; i < n; i++){
                sum2=0;
                for (int j = 0; j < n; j++)
                {
                    if(arr[j][i] == 2){
                        sum2++;
                        if(sum2 == 4){
                            cout << "Player 2 win!";
                            return 0;
                        }
                    }
                    else{
                        sum2 = 0;
                    }
                }
            }
            
            for(int i = 0; i < n-3; i++)
            {
                sum3 = 0;
                for(int j = 0; j < n; j++){
                    if(arr[j+i][j] == 1 && (j+i) < n){
                        sum3++;
                    }
                }
                if (sum3 == 4) {
                    cout << "Player 2 win!";
                    return 0;
                }
            }

            for(int i = 0; i < n - 3; i++){
                sum3 = 0;
                for(int j = 0; j < n; j++){
                    if(arr[j][j+i] == 1 && (j+i) < n){
                        sum3++;
                    }
                }
                if (sum3 == 4) {
                    cout << "Player 2 win!";
                    return 0;
                }
            }
            
            for(int i = n-1; i >= 0; i--)
            {
                if(arr[i][i] == 2){

                    sum3++;
                    if(sum3 == 4)
                    {
                        cout << "Player 2 win!";
                        return 0;
                    }
                }
                else sum3 = 0;
            }
        }
        c++;
        counter--;
    }
    cout << "There is no winner!";
    return 0;
}
