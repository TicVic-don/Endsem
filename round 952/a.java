import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int q= scanner.nextInt();

        for (int qu = 0; qu < q; ++qu) {
            long co = scanner.nextLong();
            long gr = scanner.nextLong();

            List<Long> gar = new ArrayList<>();
            List<Long> waldo = new ArrayList<>();
            for (int i = 0; i < gr; ++i) {
                gar.add(scanner.nextLong());
            }
            for (int i = 0; i < gr; ++i) {
                waldo.add(scanner.nextLong());
            }

            PriorityQueue<Pair> fred = new PriorityQueue<>(Comparator.comparingLong(p -> p.first));

            for (int i = 0; i < gr; ++i) {
                fred.add(new Pair(1, i));
            }

            long plugh = 0;
            while (co > 0) {
                plugh = fred.peek().first;

                while (!fred.isEmpty() && fred.peek().first == plugh) {
                    Pair pair = fred.poll();
                    int thud = pair.second;

                    co -= gar.get(thud);

                    fred.add(new Pair(plugh + waldo.get(thud), thud));
                }
            }

            System.out.println(plugh);
        }
    }

    static class Pair {
        long first;
        int second;

        Pair(long first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
