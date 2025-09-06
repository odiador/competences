import java.util.Scanner;

public class Aaawww {

    private static class Node {
        Node next;
        Node prev;
        boolean fav;
        char[] problems;

        Node(Node prev, boolean fav, char[] problems) {
            this.prev = prev;
            this.fav = fav;
            this.problems = problems;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nTeams = sc.nextInt();
        int m = sc.nextInt();
        int favPos = sc.nextInt();
        char[][] teams = new char[nTeams][m];

        int pending = 0;
        for (int i = 0; i < nTeams; i++) {
            teams[i] = sc.next().toCharArray();
            for (char c : teams[i]) {
                if (c == 'P') {
                    pending++;
                }
            }
        }

        int[] posPending = new int[pending];
        for (int i = 0; i < pending; i++) {
            sc.next();
            String s = sc.next().substring(6);
            int cntPend = 0;
            for (char c : s.toCharArray()) {
                if (c == 'y') cntPend++;
            }
            posPending[i] = cntPend;
        }

        Node head = null, tail = null;
        for (int i = 0; i < nTeams; i++) {
            Node newNode = new Node(tail, (i + 1) == favPos, teams[i]);
            if (tail != null) {
                tail.next = newNode;
            }
            tail = newNode;
            if (head == null) {
                head = newNode;
            }
        }

        for (int pendingValue : posPending) {
            Node itNode = head;
            while (itNode != null) {
                for (int j = 0; j < itNode.problems.length; j++) {
                    if (itNode.problems[j] == 'P') {
                        if (pendingValue == 0) {
                            itNode.problems[j] = 'R';
                        }
                        break;
                    }
                }
                itNode = itNode.next;
            }

            Node selected = head;
            int moves = pendingValue;
            while (selected != null && moves > 0) {
                selected = selected.next;
                moves--;
            }

            if (selected != null && selected.prev != null) {
                selected.prev.next = selected.next;
                if (selected.next != null) {
                    selected.next.prev = selected.prev;
                }
                selected.next = head;
                if (head != null) {
                    head.prev = selected;
                }
                head = selected;
                selected.prev = null;
            }
        }

        Node itNode = head;
        int position = 1;
        while (itNode != null) {
            if (itNode.fav) {
                System.out.println(position);
                break;
            }
            itNode = itNode.next;
            position++;
        }
        sc.close();
    }
}
