/************************************************************
 *  name : Youngwoo Park
 *  date : 10-02-2020
 *  level: l3
 *  problem source: programmers
 *  lang: C++
 *  skill:  vector sorting
 * *********************************************************/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer, numbers;
    string number;
    char instruction;
    bool before = false;
    
    for(int i = 0 ; i < operations.size() ; i++){
        before = false;
        number = "";
        for(int j = 0 ; j < operations[i].size(); j++){
            if(operations[i][j] == ' ')
                before = true;
            else if(before == false)
                instruction = operations[i][j];
            else
                number.push_back(operations[i][j]);
        }
        if(instruction == 'I'){
            //cout << "Push " << stoi(number) << endl;
            numbers.push_back(stoi(number));   
            sort(numbers.begin(), numbers.end());
        }
        else if(numbers.size() > 0){
                if(number == "-1"){
                    //cout << "Delete " << numbers[0] << endl;
                    numbers.erase(numbers.begin());
                }
                else{
                    //cout << "Delete" << numbers[numbers.size() - 1] << endl;
                    numbers.pop_back();                                    
                }

        }
    }
    if(numbers.size() == 0){
        answer = {0,0};
    }
    else if(numbers.size() == 1)
        answer = {numbers[0],numbers[0]};
    else {
        answer.push_back(numbers[numbers.size()-1]);
        answer.push_back(numbers[0]);        
    }
    return answer;
}