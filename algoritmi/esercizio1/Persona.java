public class Persona {
    private String nome;
    private String cognome;
    private Cittadinanza cit;

    public Persona(String n, String c, Cittadinanza ci){
        this.nome = n;
        this.cognome = c;
        this.cit = ci;
    }

    public void getinfo(){
        System.out.println(this.nome);
        System.out.println(this.cognome);
        System.out.println(this.cit);
    }
}
