
import java.util.Scanner;

class saes {

    static Scanner in = new Scanner(System.in);

    static int i;

    static int[] key0 = new int[16];
    static int[] key1 = new int[16];
    static int[] key2 = new int[16];

    static int[] Rotation = { 4, 5, 6, 7, 0, 1, 2, 3 };
    static int[] Shift = { 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7 };

    static int[] R_con_1 = { 1, 0, 0, 0, 0, 0, 0, 0 };
    static int[] R_con_2 = { 0, 0, 1, 1, 0, 0, 0, 0 };

    static int[][] SBox_en = { { 9, 4, 10, 11 },
            { 13, 1, 8, 5 },
            { 6, 2, 0, 3 },
            { 12, 14, 15, 7 } };
    static int[][] SBox_de = { { 10, 5, 9, 11 },
            { 1, 7, 8, 15 },
            { 6, 0, 2, 3 },
            { 12, 4, 13, 14 } };

    static int[][] col1 = { { 1, 4 },
            { 4, 1 } };
    static int[][] col2 = { { 9, 2 },
            { 2, 9 } };

    static String[][] multiply = { { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" },
            { "0", "2", "4", "6", "8", "A", "C", "E", "3", "1", "7", "5", "B", "9", "F", "D" },
            { "0", "3", "6", "5", "C", "F", "A", "9", "B", "8", "D", "E", "7", "4", "1", "2" },
            { "0", "4", "8", "C", "3", "7", "B", "F", "6", "2", "E", "A", "5", "1", "D", "9" },
            { "0", "5", "A", "F", "7", "2", "D", "8", "E", "B", "4", "1", "9", "C", "3", "6" },
            { "0", "6", "C", "A", "B", "D", "7", "1", "5", "3", "9", "F", "E", "8", "2", "4" },
            { "0", "7", "E", "9", "F", "8", "1", "6", "D", "A", "3", "4", "2", "5", "C", "B" },
            { "0", "8", "3", "B", "6", "E", "5", "D", "C", "4", "F", "7", "A", "2", "9", "1" },
            { "0", "9", "1", "8", "2", "B", "3", "A", "4", "D", "5", "C", "6", "F", "7", "E" },
            { "0", "A", "7", "D", "E", "4", "9", "3", "F", "5", "8", "2", "1", "B", "6", "C" },
            { "0", "B", "5", "E", "A", "1", "F", "4", "7", "C", "2", "9", "D", "6", "8", "3" },
            { "0", "C", "B", "7", "5", "9", "E", "2", "A", "6", "1", "D", "F", "3", "4", "8" },
            { "0", "D", "9", "4", "1", "C", "8", "5", "2", "F", "B", "6", "3", "E", "A", "7" },
            { "0", "E", "F", "1", "D", "3", "2", "C", "9", "7", "6", "8", "4", "A", "B", "5" },
            { "0", "F", "D", "2", "9", "6", "4", "B", "1", "E", "C", "3", "8", "7", "5", "A" } };

    public static void main(String[] args) {

        int [] PlainText = { 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0};
        int [] CipherText = { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1};
        int [] key = {0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1};

        // System.out.print("Enter the PlainText/CipherText of 8 bits: ");
        // int[] PlainText = new int[16];
        // for (i = 0; i < PlainText.length; i++) {
        //     PlainText[i] = in.nextInt();
        // }

        // System.out.print("Enter the Key of 10 bits: ");
        // int[] key = new int[16];
        // for (i = 0; i < key.length; i++) {
        //     key[i] = in.nextInt();
        // }

        int[] temp1 = new int[16];
        int[] temp2 = new int[16];
        int[] temp3 = new int[16];

        int[] Left = new int[8];
        int[] Right = new int[8];

        key_generation(key);

        System.out.println("1. Encryption");
        System.out.println("2. Decryption");
        System.out.print("Enter your Choice: ");

        int ch = in.nextInt();

        switch (ch) {

            case 1 -> {
                xor_ing(temp1, PlainText, key0);
                splitting(Left, Right, temp1);
                sub_nib(Left, SBox_en);
                sub_nib(Right, SBox_en);
                merging(temp1, Left, Right);
                mixing(temp2, temp1, Shift);
                Mix_col(temp2, col1);
                xor_ing(temp2, temp2, key1);
                splitting(Left, Right, temp2);
                sub_nib(Left, SBox_en);
                sub_nib(Right, SBox_en);
                merging(temp2, Left, Right);
                mixing(temp3, temp2, Shift);
                xor_ing(temp3, temp3, key2);

                System.out.print("The Cipher Text is: ");
                System.out.println(to_str(temp3));
            }

            case 2 -> {
                xor_ing(temp1, CipherText, key2);
                mixing(temp2, temp1, Shift);
                splitting(Left, Right, temp2);
                sub_nib(Left, SBox_de);
                sub_nib(Right, SBox_de);
                merging(temp2, Left, Right);
                xor_ing(temp2, temp2, key1);
                Mix_col(temp2, col2);
                mixing(temp3, temp2, Shift);
                splitting(Left, Right, temp3);
                sub_nib(Left, SBox_de);
                sub_nib(Right, SBox_de);
                merging(temp3, Left, Right);
                xor_ing(temp3, temp3, key0);

                System.out.print("The Plain Text is: ");
                System.out.println(to_str(temp3));
            }

        }

    }

    static void key_generation(int[] key) {

        int[] w0 = new int[8];
        int[] w1 = new int[8];
        int[] w2 = new int[8];
        int[] w3 = new int[8];
        int[] w4 = new int[8];
        int[] w5 = new int[8];

        int[] temp = new int[8];

        splitting(w0, w1, key);
        merging(key0, w0, w1);

        mixing(temp, w1, Rotation);
        sub_nib(temp, SBox_en);
        xor_ing(temp, temp, R_con_1);
        xor_ing(w2, temp, w0);
        xor_ing(w3, w1, w2);
        merging(key1, w2, w3);

        mixing(temp, w3, Rotation);
        sub_nib(temp, SBox_en);
        xor_ing(temp, temp, R_con_2);
        xor_ing(w4, temp, w2);
        xor_ing(w5, w4, w3);
        merging(key2, w4, w5);

    }

    static void splitting(int[] Left, int[] Right, int[] Text) {

        for (i = 0; i < Text.length / 2; i++) {
            Left[i] = Text[i];
            Right[i] = Text[i + Text.length / 2];
        }

    }

    static void merging(int[] result, int[] first, int[] second) {

        for (i = 0; i < first.length; i++) {
            result[i] = first[i];
            result[i + first.length] = second[i];
        }

    }

    static void mixing(int[] length_array, int[] result, int[] permutation) {

        for (i = 0; i < length_array.length; i++) {
            length_array[i] = result[permutation[i]];
        }

    }

    static void sub_nib(int[] arr, int[][] SBox) {

        int row_S0, row_S1, col_S0, col_S1;

        row_S0 = arr[0] * 2 + arr[1];
        col_S0 = arr[2] * 2 + arr[3];
        row_S1 = arr[4] * 2 + arr[5];
        col_S1 = arr[6] * 2 + arr[7];

        StringBuilder ans = new StringBuilder();

        for (i = 0; i < 4 - Integer.toBinaryString(SBox[row_S0][col_S0]).length(); i++) {
            ans.append("0");
        }

        ans.append(Integer.toBinaryString(SBox[row_S0][col_S0]));

        for (i = 0; i < 4 - Integer.toBinaryString(SBox[row_S1][col_S1]).length(); i++) {
            ans.append("0");
        }

        ans.append(Integer.toBinaryString(SBox[row_S1][col_S1]));

        for (i = 0; i < ans.length(); i++) {
            arr[i] = Character.getNumericValue(ans.charAt(i));
        }

    }

    static void xor_ing(int[] result, int[] ex_or1, int[] ex_or2) {

        for (i = 0; i < ex_or1.length; i++) {
            result[i] = ex_or1[i] ^ ex_or2[i];
        }

    }

    static void Mix_col(int[] arr, int[][] col) {

        String[][] temp = new String[2][2];

        int[][] ans = new int[2][2];

        temp[0][0] = (Integer.toHexString(8 * arr[0] + 4 * arr[1] + 2 * arr[2] + arr[3]));
        temp[0][1] = (Integer.toHexString(8 * arr[8] + 4 * arr[9] + 2 * arr[10] + arr[11]));
        temp[1][0] = (Integer.toHexString(8 * arr[4] + 4 * arr[5] + 2 * arr[6] + arr[7]));
        temp[1][1] = (Integer.toHexString(8 * arr[12] + 4 * arr[13] + 2 * arr[14] + arr[15]));

        ans[0][0] = Integer.parseInt(multiply[col[0][0] - 1][Integer.parseInt(temp[0][0], 16)], 16)
                ^ Integer.parseInt(multiply[col[0][1] - 1][Integer.parseInt(temp[1][0], 16)], 16);
        ans[0][1] = Integer.parseInt(multiply[col[0][0] - 1][Integer.parseInt(temp[0][1], 16)], 16)
                ^ Integer.parseInt(multiply[col[0][1] - 1][Integer.parseInt(temp[1][1], 16)], 16);
        ans[1][0] = Integer.parseInt(multiply[col[1][0] - 1][Integer.parseInt(temp[0][0], 16)], 16)
                ^ Integer.parseInt(multiply[col[1][1] - 1][Integer.parseInt(temp[1][0], 16)], 16);
        ans[1][1] = Integer.parseInt(multiply[col[1][0] - 1][Integer.parseInt(temp[0][1], 16)], 16)
                ^ Integer.parseInt(multiply[col[1][1] - 1][Integer.parseInt(temp[1][1], 16)], 16);

        StringBuilder str = new StringBuilder();

        str.append(String.format("%4s", Integer.toBinaryString(ans[0][0])).replace(' ', '0'));
        str.append(String.format("%4s", Integer.toBinaryString(ans[1][0])).replace(' ', '0'));
        str.append(String.format("%4s", Integer.toBinaryString(ans[0][1])).replace(' ', '0'));
        str.append(String.format("%4s", Integer.toBinaryString(ans[1][1])).replace(' ', '0'));

        for (i = 0; i < str.length(); i++) {
            arr[i] = Character.getNumericValue(str.charAt(i));
        }

    }

    static String to_str(int[] CipherText) {

        StringBuilder str = new StringBuilder();

        for (i = 0; i < CipherText.length; i++) {
            str.append(CipherText[i]);
            if (i != CipherText.length - 1) {
                str.append(" ");
            }
        }

        return str.toString();

    }

}