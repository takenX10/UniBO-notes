
public class test{
    public static int research(int[] v){
        int tot = -v.length - 1;
        for(int n = 0; n < v.length; n++){
            tot += v[n] - (n + 1);
        }

        return -tot;
    }

    public static int research2(int[] v){
        int l,r,m;
        l = 0;
        r = v.length - 1;
        while(l + 1 != r){
            m = (l + r)/2;
            if (v[m] == m+1){
                l = m;
            }else{
                r = m;
            }

        }
        return l+2;         // +1 per l'indice e +1 perche' e' l'elemento in mezzo
    }
    public static void main(String[] args){
        int[] v = {1,2,4,5};
        int out = research(v);
        System.out.println(out);
    }
}

