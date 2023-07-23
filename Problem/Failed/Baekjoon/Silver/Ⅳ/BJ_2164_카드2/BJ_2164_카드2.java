package BJ;
// https://www.acmicpc.net/problem/2164

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class BJ_2164_카드2 {
    private static BufferedReader br;
    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        LinkedList<Integer> deck = new LinkedList<>();
        for(int i = 1; i <= N; i++) deck.add(i); // 1 2 ... N

        while(deck.size() != 1){
            deck.remove(0);
            deck.add(deck.get(0));
            deck.remove(0);
        }
        
        System.out.println(deck.get(0));
    }
}
