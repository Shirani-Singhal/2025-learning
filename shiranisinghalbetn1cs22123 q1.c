public class Reverse_an_array {
    public static void main(String args[]) {
        int arr[] = {2, 4, 6, 8, 5, 7, 9};
        int sum = 0;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 != 0) { // check if number is odd
                sum += arr[i];
            }
        }

        System.out.println(sum);
    }
}
