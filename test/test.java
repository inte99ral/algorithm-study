package test;

import java.io.IOException;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main{
    private static final String str = "hello, world";
    private static BufferedReader br;
    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("test/input.txt"));
        
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());

        while (st.hasMoreTokens()) {
            System.out.println(st.nextToken());
        }
    }
}