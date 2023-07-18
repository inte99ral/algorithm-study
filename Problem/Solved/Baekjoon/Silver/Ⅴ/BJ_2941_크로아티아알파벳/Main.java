import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main {
  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    BufferedReader br;
    int answer;
    String line;

    br = new BufferedReader(new InputStreamReader(System.in));
    {
      line = br.readLine();
    }
    br.close();

    answer = line.length();
    for(int i = 1; i < line.length(); i++) {
      switch(line.charAt(i)) {
        case '=':
          if(line.charAt(i - 1) == 'z'){
            answer--;
            if(i > 1 && line.charAt(i - 2) == 'd') {
              answer--;
            }
          }
          else if(line.charAt(i - 1) == 'c') {
            answer--;
          }
          else if(line.charAt(i - 1) == 's') {
            answer--;
          }
          break;
        
        case '-':
          if(line.charAt(i - 1) == 'c') {
            answer--;
          }
          else if(line.charAt(i - 1) == 'd') {
            answer--;
          }
          break;

        case 'j':
          if(line.charAt(i - 1) == 'l') {
            answer--;
          }
          else if(line.charAt(i - 1) == 'n') {
            answer--;
          }
          break;
      }
    }

    System.out.println(answer);
    return;
  }
}