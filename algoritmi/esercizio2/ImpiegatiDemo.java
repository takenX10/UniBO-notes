package esercizio2;
import java.time.*;
import java.util.Date;
public class ImpiegatiDemo {
    public static Impiegato cercaGiovane(Impiegato[] v){
        Impiegato min = v[0];
        for(int i =1;i<v.length;i++){
            if(v[i].get_data().after(min.get_data())){
                min = v[i];
            }
        }
        return min;
    }
    public static void main(String args[]){
        Date eta = new Date(100);
        Impiegato alex = new Impiegato("Alex",eta, 10.5);
        Impiegato alice = new Impiegato("Alice",eta, 900.02);
        Stagista apo = new Stagista("Apo", eta, 2, 1, 1007);
        Impiegato v[] = {alex,alice,apo};
        Impiegato giovane = cercaGiovane(v);
        System.out.println(giovane.get_nome());
        System.out.println(giovane.get_stipendio());
        System.out.println(giovane.get_data());
    }
}
