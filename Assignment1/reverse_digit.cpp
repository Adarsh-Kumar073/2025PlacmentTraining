class Solution {
  public:
    int reverseDigits(int n) {
        int temp=0;
        int digit=n;
        int rev_digit=0;
        while(temp==0){
           temp=digit%10;
           rev_digit= temp;
           digit/=10;
        }
        while(digit>0){
            temp= digit%10;
            rev_digit= rev_digit*10+temp;
            digit/=10;
        }
        return rev_digit;
    }
};