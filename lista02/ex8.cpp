#include <stdio.h>
#include <iostream>

//classe para numeros complexos
class C
{
private:
    double _real;
    double _imag;

public:
    C(double real = 0, double imag = 0) : _real(real), _imag(imag) {}

    C& operator=(const C& a)
    {//copia
        _real = a._real;
        _imag = a._imag;
        return *this;
    };

    C operator-()
    {//conjugar um numero complexo
        C aux;
        aux._imag = -_imag;
        aux._real = -_real;
        return aux;
    };

    friend C operator+(const C& a, const C& b)
    {//operação de adição
        C soma;
        soma._real = a._real + b._real;
        soma._imag = a._imag + b._imag;
        return soma;
    };

    friend C operator-(const C& a, const C& b)
    {//operação de substração
        C sub;
        sub._real = a._real - b._real;
        sub._imag = a._imag - b._imag;
        return sub;
    };

    friend C operator*(const C& a, const C& b)
    {//operaçao de multiplicação
        C mult;
        mult._real = (a._real * b._real) - (a._imag * b._imag);
        mult._imag = (a._real * b._imag) + (a._imag * b._real);
        return mult;
    };

    friend C operator/(const C& a, const C& b)
    { //operador para operação de adição de dois numeros complexos
        // z1 = a + bi e z2 = c+di
        //zi    (a + bi) (c-di)     (ac + bd) + (bc + ad)i
        //--- = ----------------- = ----------------------
        //z2    (c + di) (c-di)          (c² + d²)
        C mult;
        double denominador = b._real * b._real + b._imag * b._imag;
        mult._real = (a._real * b._real + a._imag * b._imag) / denominador;
        mult._imag = (a._imag * b._real - a._real * b._imag) / denominador;
        return mult;
    };

    double parte_real() const
    {//retorna somente a parte real
         return _real;
    };
    double parte_imag() const 
    { //retorna somente a parte imaginanaria
        return _imag; 
    };

    virtual std::ostream& imprimir(std::ostream& aux) const
    {
        aux << parte_real()  << " + " << parte_imag() << "i";
        
        return aux;
    };

    friend std::ostream& operator<<(std::ostream& aux, const C& c)
    {
        return c.imprimir(aux);
    };
};

//classe dos reais que herdam propriedades dos comlexos
class R : public C
{
public:
    R(double real = 0) : C(real, 0) {}

    std::ostream& imprimir(std::ostream& aux) const override
    {
        aux << parte_real();
        return aux;
    };
};

//classe dos racionais que herda os reais
class Q : public R
{
private:
    long int _numerador;
    long int _denominador;

   long long int calculo_mdc(long long int a, long long int b ){
        long long int resto = 0;
        //printf(" MDC a %lld b %lld \n",a, b);

        if( a == 0)
        {
            return b;
        }
         if(b == 0)
        {
            return a;
        }
        if(a == b)
        {
            //quando ambos forem iguais, o mdc será 
            return a;
        }
        while(b != 0)
        {
                resto = a % b;
                a = b;
                b = resto;
                
        }
        //printf("Resto  %lld \n", resto);
       return a;
    }
    //funções responsáveis por reduzir a fração
    void reduz(){
        if(_numerador == 0)
        {
            _numerador = 0;
            _denominador = 1;
            return;
        }
        long long int divisor = calculo_mdc(_numerador, _denominador);
        _numerador /= divisor;
        _denominador /= divisor;

        //verificando se o dennominador é negativo  
         if(_denominador < 0)
        {
            _numerador = -_numerador ;
            _denominador = -_denominador;
        }
        else{
        _numerador = _numerador;
        _denominador = _denominador;
        }
    };


public:
    Q(int num = 0, int deno = 1) : R((double)num / deno), _numerador(num), _denominador(deno) {}

    Q(const C& aux) : R(aux.parte_real()){
        _numerador = aux.parte_real() * 1e8;
        _denominador = 1e8;

        reduz();
    }
    std::ostream& imprimir(std::ostream& aux) const override
    {
        aux << _numerador;
        if (_denominador != 1)
            aux << "/" << _denominador;
        return aux;
    };
};

//classe dos inteiros que herda os racionais
class Z : public Q
{
public:
    Z(int num = 0) : Q(num, 1) {}

    std::ostream& imprimir(std::ostream& aux) const override
    {
        //Imprime somente a arte Real de Z
        if(this->parte_real() >0){
            aux << "+" << parte_real();
        }
        else
            aux << parte_imag;
       
        return aux;
    };
};

//classe dos naturais que herda os inteiros
class N : public Z
{
public:
    N(int real = 0) : Z(real) {}

    std::ostream& imprimir(std::ostream& os) const override
    {
        os << parte_real() ;
        return os;
    };
};

int main() {
const int numObjetos = 117;
C** objetos = new C*[numObjetos];
    
    objetos[0] = new R(136.17927019765375);
    objetos[1] = new N(715430289);
    objetos[2] = new Z(1358842560);
    objetos[3] = new C(6628.509756002266, -1680.8883684406937);
    objetos[4] = new N(1752816932);
    objetos[5] = new Q(-1736942887, 1454188455);
    objetos[6] = new Z(-841029268);
    objetos[7] = new N(893299679);
    objetos[8] = new R(8487.066810587388);
    objetos[9] = new C(1028.2434408856261, -1254.0232746513302);
    objetos[10] = new Q(-478348855, 1338536107);
    objetos[11] = new C(-6848.485516047627, -2480.9784560370063);
    objetos[12] = new Q(-1058085296, 841695940);
    objetos[13] = new N(482437043);
    objetos[14] = new Q(2039687856, 1831829324);
    objetos[15] = new R(-1153.0710593040676);
    objetos[16] = new N(288541652);
    objetos[17] = new C(-1543.325184674497, 5548.385069388121);
    objetos[18] = new N(194593844);
    objetos[19] = new Z(-1468321272);
    objetos[20] = new Q(695976718, 570804868);
    objetos[21] = new R(4624.049043164068);
    objetos[22] = new C(1294.1798340680252, -7318.85807358873);
    objetos[23] = new Z(1696787391);
    objetos[24] = new Q(-2108156493, 1612448124);
    objetos[25] = new N(139797888);
    objetos[26] = new R(-8040.339448125446);
    objetos[27] = new Q(920853280, 1183979869);
    objetos[28] = new Z(-1820354979);
    objetos[29] = new R(2142.932067352527);
    objetos[30] = new C(-7222.624992161351, -9407.480019388397);
    objetos[31] = new N(697819919);
    objetos[32] = new R(9673.077101933897);
    objetos[33] = new C(1847.7154685420774, 1531.8432511254196);
    objetos[34] = new Z(451832285);
    objetos[35] = new R(-944.1630412814666);
    objetos[36] = new N(615098950);
    objetos[37] = new Q(-757414677, 1599964722);
    objetos[38] = new Z(-34605171);
    objetos[39] = new R(9109.815953561007);
    objetos[40] = new N(1710629269);
    objetos[41] = new C(6417.746890220667, -9602.460203169205);
    objetos[42] = new Q(888600665, 1561274848);
    objetos[43] = new N(291066202);
    objetos[44] = new C(-3650.3583720439356, -6726.875195877331);
    objetos[45] = new Z(1367112494);
    objetos[46] = new R(-8168.460241597597);
    objetos[47] = new Q(-270024772, 815958788);
    objetos[48] = new Z(-1890967927);
    objetos[49] = new R(-7322.434234166475);
    objetos[50] = new Q(-831209510, 887962978);
    objetos[51] = new R(2580.59011067189);
    objetos[52] = new Q(304130964, 919770329);
    objetos[53] = new R(3871.300862732667);
    objetos[54] = new Q(-196095338, 2038884878);
    objetos[55] = new N(83854452);
    objetos[56] = new C(-732.4141197880581, 8728.662656735578);
    objetos[57] = new Q(409600395, 351196511);
    objetos[58] = new R(2652.599105572386);
    objetos[59] = new Q(-210002059, 1691782963);
    objetos[60] = new N(1573497071);
    objetos[61] = new C(6829.642061300921, 9979.501534007031);
    objetos[62] = new N(914974378);
    objetos[63] = new R(-1805.3363390169452);
    objetos[64] = new Z(-885169107);
    objetos[65] = new C(-3150.750941709506, -5118.945457381549);
    objetos[66] = new N(1122996401);
    objetos[67] = new R(1500.8564601911712);
    objetos[68] = new Z(-397698221);
    objetos[69] = new Q(1879765090, 17945879);
    objetos[70] = new N(302323207);
    objetos[71] = new C(3221.5085598623555, 6575.1096273726);
    objetos[72] = new R(7802.153789662683);
    objetos[73] = new Z(1336857128);
    objetos[74] = new N(2125472529);
    objetos[75] = new C(2872.7415982726234, -9208.743138284428);
    objetos[76] = new Q(-1375333202, 2020108958);
    objetos[77] = new C(2809.192345221283, 823.214271077899);
    objetos[78] = new Q(-876106285, 784604367);
    objetos[79] = new C(4440.798980411948, -470.6319852983579);
    objetos[80] = new Z(449731104);
    objetos[81] = new N(107381429);
    objetos[82] = new Z(585913885);
    objetos[83] = new C(-1633.7543511354306, 889.8066142013158);
    objetos[84] = new R(5117.096572249375);
    objetos[85] = new Q(-989767291, 2108800126);
    objetos[86] = new Z(-1734516970);
    objetos[87] = new C(-5953.462478908868, 2068.432316953391);
    objetos[88] = new Q(-655719177, 319112869);
    objetos[89] = new Z(30397822);
    objetos[90] = new Q(-41071394, 1896467998);
    objetos[91] = new Z(1519201450);
    objetos[92] = new Q(-1329797137, 19270427);
    objetos[93] = new C(-2365.5860844070075, 2183.9993133575845);
    objetos[94] = new Z(2047453986);
    objetos[95] = new N(1329438091);
    objetos[96] = new C(7702.398207065824, -7668.300126866352);
    objetos[97] = new Q(-1545279635, 526740660);
    objetos[98] = new C(-3411.168084638969, -2421.024689034368);
    objetos[99] = new Z(1017908636);
    objetos[100] = new Q(-1099888235, 225457604);
    objetos[101] = new Z(427820222);
    objetos[102] = new Q(-2133557336, 690440850);
    objetos[103] = new C(4314.832049080471, -77.68447519789515);
    objetos[104] = new R(-6432.165480482748);
    objetos[105] = new N(1090915326);
    objetos[106] = new C(-4910.041954023325, -9440.236097305717);
    objetos[107] = new Q(-1492667967, 1975138113);
    objetos[108] = new R(-4201.740836477741);
    objetos[109] = new Q(-275311150, 1465389713);
    objetos[110] = new R(-9340.327768736162);
    objetos[111] = new C(4272.370780363874, 974.970658222177);
    objetos[112] = new N(822478306);
    objetos[113] = new C(-458.7347065380909, -556.8488092641492);
    objetos[114] = new R(9846.725849869843);
    objetos[115] = new Z(-1046135574);
    objetos[116] = new C(323.92876936890);

for (int i = 0; i < numObjetos; ++i)
std::cout << *objetos[i] << std::endl;
for (int i = 0; i < numObjetos; ++i)
delete objetos[i];
return 0;
}