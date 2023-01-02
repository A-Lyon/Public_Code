public class MyFunctions implements TestingFunctions{

    @Override
    public int greatestCommonDivisor(int a, int b) {


        if ((a==0)&&(b!=0)){
            return b;
        }else if ((a!=0)&&(b==0)) {
            return a;
        }else if ((a<0)||(b<0)){
            return -1;
        }

        if (a%b==0){
            return b;
        }else if (b%a==0){
            return a;
        }else return greatestCommonDivisor(b%a, a);

    }





    @Override
    public void reverseWindow(int[] arr, int index1, int index2) throws IndexOutOfBoundsException {

        if(index1 > index2){
            int temp = index1;
            index1 = index2;
            index2 = temp;
        } // (3,0) -> (0,3)

        //(0,3)
        //[1, 2, 3, 4, 5]
        //[+  -  +     ]

        for (int i = index1; i < (index2/2); i++){
            int temp = arr[i];
            arr[i] = arr[index2 - (1 + i)];
            arr[index2 - (1 + i)]= temp;
        }


    }
}
