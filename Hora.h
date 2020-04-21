class Hora
{
public:
	Hora(); //defalt
  Hora(int h, int m); // parametros 
  void setH(int h){hh = ((h >= 0 && h < 24) ? h:0);};
	void setMin(int m){mm = ((m >= 0 && m <= 59) ? m:0);};
	int getH(){return hh;};;
	int getMin(){return mm;};
  void Muestra();
private:
	int hh, mm;
};
Hora::Hora(){
      hh = 0;
      mm =0; 
}
Hora::Hora(int h, int m){
    hh = h;
    mm = m;
}
void Hora::Muestra(){
  cout << "Hora "<< hh << ":" << mm ;
}