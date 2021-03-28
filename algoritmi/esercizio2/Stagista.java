package esercizio2;
import java.time.*;
import java.util.Date;
public class Stagista extends Impiegato{
    protected int numero_stagista;
    protected int numero_presenze;
    public Stagista(String n, Date d, double s, int np, int ns){
        super(n,d,s);
        this.numero_stagista = ns;
        this.numero_presenze = np;
    }

    public void set(int np, int ns){
        this.numero_stagista = ns;
        this.numero_presenze = np;
    }
    public int get_presenze(){
        return this.numero_presenze;
    }
    public int get_stagista(){
        return this.numero_stagista;
    }

}
