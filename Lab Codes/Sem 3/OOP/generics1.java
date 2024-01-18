import java.util.*;

class Gen<T extends Object> {
    T[] name=(T[])new Object[10];
	int length = 0;
	void append(T v){
		name[length++] = v;
	}
	void display(){
		for (int i = 0; i<length; i++) {
			System.out.println(name[i]);
		}
	}
}

class generics1
{
    public static void main(String[] args) {
    		Gen<String> objs = new Gen<>();
    		objs.append("hello");
            objs.append("hi");
            Gen<Integer> obji = new Gen<>();
    		obji.append(1);
            obji.append(69);
    		objs.display();
            obji.display();
       }
}