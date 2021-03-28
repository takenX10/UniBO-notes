package esercizio2;
import java.time.*;
import java.util.Date;

public class Impiegato extends Persona{
    public double stipendio;
    public Impiegato(String n, Date d, double s){
        super(n,d);
        this.stipendio = s;
    }
    public void set(String n, Date d, double s){
        super.set(n,d);
        this.stipendio = s;
    }
    public double get_stipendio(){
        return this.stipendio;
    }

}
