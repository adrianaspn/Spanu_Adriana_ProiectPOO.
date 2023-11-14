#include <iostream>
#include <cstring>

using namespace std;

class Jurnalist {
private:
	const int ID;
	static int nrJurnalisti;
	char* nume;
	string prenume;
	int varsta;
	float anexp;

public:

	Jurnalist() : ID(++nrJurnalisti) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(nume, strlen("Anonim") + 1, "Anonim");
		this->prenume = "Anonim";
		this->varsta = 0;
		this->anexp = 0;

	}

	Jurnalist(string prenume, int varsta) : ID(++nrJurnalisti) {
		this->prenume = prenume;
		this->varsta = varsta;
		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(nume, strlen("Anonim") + 1, "Anonim");
		this->anexp = 0;
	}

	Jurnalist(const char* nume, string prenume, int varsta, float anexp) : ID(++nrJurnalisti) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->prenume = prenume;
		this->varsta = varsta;
		this->anexp = anexp;

	}

	Jurnalist(const Jurnalist& jurnalist) :ID(jurnalist.ID)
	{
		this->prenume = jurnalist.prenume;
		this->varsta = jurnalist.varsta;
		this->anexp = jurnalist.anexp;
		this->nume = new char[strlen(jurnalist.nume) + 1];
		strcpy_s(this->nume, strlen(jurnalist.nume) + 1, jurnalist.nume);

	}
	Jurnalist operator=(const Jurnalist& j) {
		if (this != &j) {
			this->prenume = j.prenume;
			this->varsta = j.varsta;
			this->anexp = j.anexp;

			delete[] this->nume;
			this->nume = new char[strlen(j.nume) + 1];
			strcpy_s(this->nume, strlen(j.nume) + 1, j.nume);
		}
		return *this;
	}

	bool operator<(const Jurnalist& jurn) const {
		return this->varsta < jurn.varsta;
	}

	bool operator>(const Jurnalist& jurn) const {
		return this->varsta > jurn.varsta;
	}

	bool operator==(const Jurnalist& jurn) const {
		return (this->varsta == jurn.varsta && this->anexp == jurn.anexp && this->prenume == jurn.prenume && strcmp(this->nume, jurn.nume) == 0);
	}

	~Jurnalist() {
		delete[] this->nume;

	}

	int getID() {
		return this->ID;
	}

	static int getNrJurnalisti() {
		return nrJurnalisti;
	}

	static void setNrJurnalisti( int nrJurnalisti) {
		Jurnalist::nrJurnalisti = nrJurnalisti;
	}

	int getVarsta() {
		return this->varsta;
	}

	void setVarsta(int valoareNoua) {
		if (valoareNoua > 0) {
			this->varsta = valoareNoua;
		}
		else {
			throw "Valoare negativa.";
		}
	}

	string getPrenume() {
		return this->prenume;
	}
	void setPrenume(string prenume) {
		this->prenume = prenume;
	}
	
	void setNume(const char* nume) {
		delete[]this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	float getAnexp() {
		return this->anexp;
	}
	void setAnexp(float anexp) {
		this->anexp = anexp;
	}


	void main() {
		Jurnalist jurnalist;
		cout << Jurnalist::getNrJurnalisti();
	}

	void afisare() {
		cout << " Jurnalistul " << nume << " " << prenume << " cu ID-ul " << ID << " are varsta de " << varsta << " ani si experienta de " << anexp << " ani.";


	}

	static void AfisareNrJurnalisti() {
		cout << "Numarul total de jurnalisti este: " << nrJurnalisti << endl;
	}
};
int Jurnalist::nrJurnalisti = 0;


class Camera {
private:
	string marca;
	const int id;
	int nrComponente;
	float* preturi;
	static int nrCamere; 

public:
	
	Camera() :id(++nrCamere) {
		this->marca = "Necunoscuta";
		this->nrComponente = 0;
		this->preturi = NULL;
		
	}

	Camera(string marca, int nrComponente) : id(++nrCamere) {
		this->marca = marca;
		this->nrComponente = nrComponente;
		this->preturi = NULL;
	}

	Camera(string marca, int nrComponente, float* preturi) : id(++nrCamere) {
		this->marca = marca;
		this->nrComponente = nrComponente;
		this->preturi = new float[this->nrComponente];
		for (int i = 0; i < nrComponente; i++)
		{
			this->preturi[i] = preturi[i];
		}
		
	}

	Camera(const Camera& camera) :id(camera.id)
	{
		this->marca = camera.marca;
		this->nrComponente = camera.nrComponente;
		this->preturi = new float[camera.nrComponente];
		for (int i = 0; i < camera.nrComponente; i++)
		{
			this->preturi[i] = camera.preturi[i];
		}
		
	}

	Camera& operator=(const Camera& camera) {
		if (this != &camera) {
			this->marca = camera.marca;
			this->nrComponente = camera.nrComponente;

			delete[] this->preturi;
			this->preturi = new float[this->nrComponente];
			for (int i = 0; i < this->nrComponente; i++) {
				this->preturi[i] = camera.preturi[i];
			}
		}
		return *this;
	}


	bool operator!=(const Camera& cam) const {
		return (this->marca != cam.marca || this->nrComponente != cam.nrComponente);
	}

	Camera operator+(const Camera& camera) const {
		Camera aux = *this;
		aux.nrComponente = this->nrComponente + camera.nrComponente;	
		
		if (aux.preturi != NULL) {
			delete[]aux.preturi;
		}
		aux.preturi = new float[aux.nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			aux.preturi[i] = this->preturi[i];
		}
		int j = 0;
		for (int i = this->nrComponente; i < aux.nrComponente; i++) {
			aux.preturi[i] = camera.preturi[j];
			j++;
		}

		return aux;
	}


	Camera operator-(float valoare) const {	

		if (preturi != NULL) {
			for (int i = 0; i < nrComponente; i++) {
				preturi[i] = preturi[i] - valoare;
			}
		}


		return *this;
	}

	~Camera() {
		delete[] this->preturi;
	}

	void afisare() {
		cout << endl << "Camera " << this->marca << " , id-ul " << this->id << " are " << this->nrComponente << " componente si preturile sunt: ";
		if (this->preturi != nullptr) {
			for (int i = 0; i < this->nrComponente; i++) {
				cout << this->preturi[i] << " ";
			}

		}
		else {
			cout << "indisponibile";
		}
	}


	static int getNrCamere() {
		return nrCamere;
	}

	string getMarca() {
		return this->marca;
	}
	void setMarca(string marca) {
		this->marca = marca;
	}

	int getNrComponente() {
		return this->nrComponente;
	}

	void setNrComponente(int nouaValoare) {
		if (nouaValoare > 0) {
			this->nrComponente = nouaValoare;
		}
		else {
			throw exception();
		}
	}

	void setPreturi(int nrComponente, float* preturiNoi) {

		setNrComponente(nrComponente);

		if (this->preturi != nullptr)
			delete[] this->preturi;

		this->preturi = new float[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			this->preturi[i] = preturiNoi[i];
		}

		delete[] preturiNoi;

	}

	float* getPreturi() {
		
		float* preturiDeReturnat = new float[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			preturiDeReturnat[i] = this->preturi[i];
		}
		return preturiDeReturnat;
	}
	static void AfisareNrCamere() {
		cout << "Numarul total de camere este: " << nrCamere << endl;
	}
};

int Camera::nrCamere = 0;


class Articol {
private:
	const int ID;
	static int nrArticole;
	char* titlu;
	string autor;
	int anPublicare;

public:
	Articol() : ID(++nrArticole) {
		this->titlu = new char[strlen("Anonim")+1];
		strcpy_s(titlu, strlen("Anonim") + 1, "Anonim");
		this->autor = "Anonim";
		this->anPublicare = 0;
	}

	Articol(string autor, int anPublicare) : ID(++nrArticole) {
		this->titlu = new char[strlen("Anonim") + 1];
		strcpy_s(titlu, strlen("Anonim") + 1, "Anonim");
		this->autor = autor;
		this->anPublicare = anPublicare;
	}

	Articol(const char* titlu, string autor, int anPublicare) : ID(++nrArticole) {
		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		this->autor = autor;
		this->anPublicare = anPublicare;
	}

	Articol(const Articol& articol) : ID(articol.ID) {
		this->autor = articol.autor;
		this->anPublicare = articol.anPublicare;
		if (articol.titlu != nullptr) {
			this->titlu = new char[strlen(articol.titlu) + 1];
			strcpy_s(this->titlu, strlen(articol.titlu) + 1, articol.titlu);
		}
		else {
			this->titlu = nullptr;
		}
	}

	Articol& operator=(const Articol& articol) {
		if (this != &articol) {
			this->autor = articol.autor;
			this->anPublicare = articol.anPublicare;

			delete[] this->titlu;
			this->titlu = new char[strlen(articol.titlu) + 1];
			strcpy_s(this->titlu, strlen(articol.titlu) + 1, articol.titlu);
		}
		return *this;
	}

	Articol operator++ () {
		anPublicare++;
		return *this;
	}

	Articol operator-- () {
		anPublicare--;
		return *this;
	}


	~Articol() {
		delete[] this-> titlu;
	}

	int getID() {
		return ID;
	}
	const char* getTitlu() {
		return this->titlu; 
	}
	void setTitlu(const char* nouTitlu) {
		delete[] this->titlu; 
		this->titlu = new char[strlen(nouTitlu) + 1]; 
		strcpy_s(this->titlu, strlen(nouTitlu) + 1, nouTitlu); 
	}
	static int getNrArticole() {
		return nrArticole;
	}

	static void setNrArticole(int nrArticole) {
		Articol::nrArticole = nrArticole;
	}

	string getAutor() {
		return autor;
	}

	void setAutor(string autor) {
		this->autor = autor;
	}

	int getAnPublicare() {
		return anPublicare;
	}

	void setAnPublicare(int anPublicare) {
		this->anPublicare = anPublicare;
	}

	void afisare() {
		cout << "Articolul '" << titlu << "' scris de " << autor << " cu ID-ul " << ID << " a fost publicat in anul " << anPublicare << ".\n";
	}
	static void AfisareNrArticole() {
		cout << "Numarul total de articole este: " << nrArticole << endl;
	}
};

int Articol::nrArticole = 0;

void ProcesareJurnalist(Jurnalist& jurn) {
	cout << "Procesare Jurnalist: " << jurn.getID() << endl;
	
}

void ProcesareArticol(Articol& ART) {
	cout << "Procesare Articol: " << ART.getAutor() << endl;
	
}

int main() {
	
	Jurnalist j1;
	j1.afisare();
	cout << endl;
	
	Jurnalist j2("Adriana",19);
	j2.afisare(); 
	

	j2.setNume("Spanu");
	cout << endl;
	j2.afisare();
	cout << endl;
	j2.setAnexp(5);
	j2.afisare();
	cout << endl;
	if (j2.getAnexp() > 0) 
		cout << "Angajat calificat";
	else
		cout << "Angajat necalificat";
	cout << endl<< endl;
	cout << "ID: " << j2.getID() << endl;
	cout << "Prenume: " << j2.getPrenume() << endl;
	cout << "Varsta: " << j2.getVarsta() << endl;
	cout << "An experienta: " << j2.getAnexp() << endl << endl;
	
	Jurnalist j3("Railean", "Dan", 22, 3);
	j3.afisare();
	cout << endl;
	Jurnalist j4(j3);
	j4.afisare();
	cout << endl << endl;

	j1 = j3; 
	j1.afisare();
	cout << endl;

	
	if (j2 < j3) {
		cout <<  j2.getPrenume() << " este mai tanar decat " << j3.getPrenume() << endl;
	}
	else if (j2 > j3) {
		cout << j2.getPrenume() << " este mai in varsta decat " << j3.getPrenume() << endl;
	}
	else {
		cout << j2.getPrenume() << " si " << j3.getPrenume() << " au aceeasi varsta" << endl;
	}
	if (j1 == j2) {
		cout << "Jurnalistii sunt identici." << endl;
	}
	else
		cout << "Jurnalistii sunt diferiti." << endl;

	


	Jurnalist::AfisareNrJurnalisti();

	
	Camera c1;
	c1.afisare();

	Camera c2("Nikon", 4);
	c2.afisare();



	Camera c3("Sony", 3, new float[3] {1200, 1500, 1800});
	c3.afisare();
	cout << endl;
	cout << "Marca camerei: " << c3.getMarca() << endl;
	cout << "Numar de componente: " << c3.getNrComponente() << endl;
	
	Camera c4(c3);
	c4.afisare();
	cout << endl;
	Camera c5("Canon", 2, new float[2] {15012, 208274});
	c5.afisare();
	Camera c6;
	cout << endl;
	

	c3.setPreturi(4, new float[4] {2000, 2200, 2500, 2700});
	float* preturiC3 = c3.getPreturi();
	for (int i = 0; i < c3.getNrComponente(); i++) {
		cout << "Pretul componentei " << i + 1 << ": " << preturiC3[i] << endl;
	}
	delete[] preturiC3;  

	cout << endl;
	
	/*
	if (c1 != c2) {
        cout << "Camerele sunt diferite." << endl;
    }

	c6 = c2 + c3;
	c6.afisare();
	c6 = c6 - 15;
	cout << endl;
	c6.afisare();*/
  

	Camera::AfisareNrCamere();


	Articol a1;
	a1.afisare();
	
	Articol a2("Stamati Maria", 2023);
	a2.afisare();
	
	++a2;
	cout << endl;
	a2.afisare();

	Articol a3("Introducere in Machine Learning", "Alex", 2022);
	a3.afisare();
	cout << "Titlul articolului: " << a3.getTitlu() << endl;
	cout << "Autorul: " << a3.getAutor() << endl;
	cout << "Anul publicarii: " << a3.getAnPublicare() << endl;

	a3.setTitlu("Artele Programarii Orientate Obiect");
	a3.setAutor("Tania");
	a3.setAnPublicare(2024);

	a3.afisare();

	--a3;
	cout << endl;
	a3.afisare();

	Articol a4(a3);
	a4.afisare();

	Articol::AfisareNrArticole();

	ProcesareJurnalist(j2);
	ProcesareArticol(a3);

	return 0;
}


//J: =, <, >, ==
//C: =, +, -, !=
//A: =, ++, --, 
