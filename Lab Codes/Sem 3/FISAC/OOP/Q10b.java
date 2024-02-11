import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class ListMerger<T> {
    public List<T> mergeLists(List<T> list1, List<T> list2) {
        List<T> mergedList = new ArrayList<>();
        int maxLength = Math.max(list1.size(), list2.size());

        for (int i = 0; i < maxLength; i++) {
            if (i < list1.size()) {
                mergedList.add(list1.get(i));
            }
            if (i < list2.size()) {
                mergedList.add(list2.get(i));
            }
        }

        return mergedList;
    }

    
}

public class Q10b {
    public static void main(String[] args) {
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        int key=1,toggle=0;
        Scanner sc=new Scanner(System.in);
        while(key==1)
        {
            System.out.println("Enter element:- ");
            int data=sc.nextInt();
            if(toggle==0) list1.add(data);
            else list2.add(data);
            toggle=1-toggle;
            System.out.println("Do you want to enter more elements? (1/0):-");
            key=sc.nextInt();
        }

        ListMerger<Integer> merger = new ListMerger<>();
        List<Integer> mergedList = merger.mergeLists(list1, list2);

        System.out.println("Merged List: " + mergedList);
    }
}
