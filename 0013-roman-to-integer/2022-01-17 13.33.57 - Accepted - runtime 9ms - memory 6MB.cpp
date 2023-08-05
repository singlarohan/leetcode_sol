class Solution {
public:
    int romanToInt(string roman){
    int intg{0};

    for(int i = 0; i < roman.length(); i++){
        if(roman[i] == 'I'){
            if((roman[i+1] == 'V' || roman[i+1] == 'X')){
                if(roman[i+1] == 'V')
                intg += 4;
                else 
                intg += 9;
                i++;
            }
            else
            intg++;
        }
        
        else if(roman[i] == 'V')
        intg += 5;

        else if(roman[i] == 'X'){
            if((roman[i+1] == 'L' || roman[i+1] == 'C')){
                if(roman[i+1] == 'L')
                intg += 40;
                else 
                intg += 90;
                i++;
            }
            else
            intg += 10;
        }

        else if(roman[i] == 'L')
        intg += 50;

        else if(roman[i] == 'C'){
            if((roman[i+1] == 'D' || roman[i+1] == 'M')){
                if(roman[i+1] == 'D')
                intg += 400;
                else 
                intg += 900;
                i++;
            }
            else
            intg += 100;
        }
        
        else if(roman[i] == 'D')
        intg += 500;
        
        else if(roman[i] == 'M')
        intg += 1000;
    }
    return intg;
}
};