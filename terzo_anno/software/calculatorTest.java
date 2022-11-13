import static org.junit.Assert.assertEquals;
import org.junit.Test;
import Calculator;

public class calculatorTest {

    @Test
    public void testCalculator(){
        assertEquals(2, Calculator.calculate("1,1"));
        assertEquals(11, Calculator.calculate("11"));
        assertEquals(2, Calculator.calculate(" 1,1"));
        assertEquals(2, Calculator.calculate("1,1 "));
        assertEquals(0, Calculator.calculate(",1,1"));
        assertEquals(2, Calculator.calculate("1,1,"));
        assertEquals(3, Calculator.calculate("1,1,1"));
        assertEquals(0, Calculator.calculate(","));
        assertEquals(0, Calculator.calculate(""));
        assertEquals(0, Calculator.calculate("11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111,1"));
        assertEquals(2, Calculator.calculate("001,1"));
        assertEquals(10, Calculator.calculate("9,1"));
        assertEquals(0, Calculator.calculate("1, 1,1"));
        assertEquals(0, Calculator.calculate(" 1, ,1"));
        assertEquals(0, Calculator.calculate("a"));
        assertEquals(0, Calculator.calculate("1,a"));
        assertEquals(0, Calculator.calculate("a,1"));
        assertEquals(0, Calculator.calculate("1,a,1"));
        assertEquals(0, Calculator.calculate("a1a,1"));
        assertEquals(0, Calculator.calculate("a,a"));

    }
    
}
