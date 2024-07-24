 abstract class animal {
    public void eat(){
        System.out.println("I am eating");
    }
    animal(){
        System.out.println("I am an animal");
    }
}

class A extends animal{
    public void print(){
        System.out.println("I am a cat");
    }
    public void eat(){
        System.out.println("I am eating fish");
    }  
    A(){
        System.out.println("I am a cat constuctor");
    } 
}


public class question {
    public static void main(String[] args) {
        // A a = new A();
        animal a12 = new animal() {
            @Override
            public void eat() {
                System.out.println("I am eating meat");
            }
        };
        a12.eat();

    }
}