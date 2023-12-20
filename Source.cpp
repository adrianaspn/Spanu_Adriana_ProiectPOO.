#include <iostream>
#include <cstring>
#include <fstream>

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

	friend ostream& operator<<(ostream& out, const Jurnalist& jurnalist) {
		out << "ID: " << jurnalist.ID << endl;
		out << "Nume: " << jurnalist.nume << "; " << endl;
		out << "Prenume: " << jurnalist.prenume << "; " << endl;
		out << "Varsta: " << jurnalist.varsta << "; " << endl;
		out << "Ani experienta: " << jurnalist.anexp << "; " << endl;
		out << endl;
		return out;
	}

	friend ofstream& operator<<(ofstream& file, const Jurnalist& jurnalist) {
		file << jurnalist.nume << " " << jurnalist.prenume << " ";
		file << jurnalist.varsta << " " << jurnalist.anexp << endl;
		return file;
	}

	friend istream& operator>>(istream& in, Jurnalist& jurnalist) {
		cout << "Nume: ";
		char aux[100];
		in>>aux;
		delete[] jurnalist.nume;
		jurnalist.nume = new char[strlen(aux) + 1];
		strcpy_s(jurnalist.nume, strlen(aux) + 1, aux);

		cout << "Prenume: ";
		in >> jurnalist.prenume;
		cout << "Varsta: ";
		in >> jurnalist.varsta;
		cout << "Ani de experienta: ";
		in >> jurnalist.anexp;
		return in;

	}

	friend ifstream& operator>>(ifstream& in, Jurnalist& jurnalist) {
		char aux[100];
		in >> aux;
		jurnalist.nume = new char[strlen(aux) + 1];
		strcpy_s(jurnalist.nume, strlen(aux) + 1, aux);

		in >> jurnalist.prenume;
		in >> jurnalist.varsta;
		in >> jurnalist.anexp;
		return in;
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

	static void setNrJurnalisti(int nrJurnalisti) {
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
			if (this->preturi != NULL) {
				delete[] this->preturi;
			}
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
		aux.preturi = new float[aux.nrComponente + camera.nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			aux.preturi[i] = this->preturi[i];
		}
		int j = 0;
		for (int j = this->nrComponente; j < aux.nrComponente; j++)
			aux.preturi[j] = camera.preturi[j - this->nrComponente];

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

	friend ostream& operator<<(ostream& consola, const Camera& c) {
		consola << "Marca: " << c.marca << "; " << endl;
		consola << "ID Camera: " << c.id << "; " << endl;
		consola << "Numar Componente: " << c.nrComponente << "; " << endl;
		consola << "Numar Camere: " << c.nrCamere << "; " << endl;
		consola << "Preturi: ";
		for (int i = 0; i < c.nrComponente; i++) {
			consola << c.preturi[i] << ", ";
		}

		consola << endl;
		return consola;
	}

	friend ofstream& operator<<(ofstream& file, Camera& camera) {
		file << camera.marca << " " << camera.id << " ";
		file << camera.nrComponente << " " << camera.nrCamere << " ";
		for (int i = 0; i < camera.nrComponente; i++) {
			file << camera.preturi[i] << " ";
		}
		return file;
	}

	friend istream& operator>>(istream& in, Camera& c) {
		cout << "Marca: ";
		in >> c.marca;
		cout << "Numar Componente: ";
		in >> c.nrComponente;
		if (c.preturi) {
			delete[] c.preturi;
		}
		c.preturi = new float[c.nrComponente];
		for (int i = 0; i < c.nrComponente; i++) {
			cout << "Preturi " << i + 1 << ": ";
			in >> c.preturi[i];
		}
		return in;

	}

	friend ifstream& operator>>(ifstream& in, Camera& c) {
		in >> c.marca;
		in >> c.nrComponente;
		if (c.preturi) {
			delete[] c.preturi;
		}
		c.preturi = new float[c.nrComponente];
		for (int i = 0; i < c.nrComponente; i++) {
			in >> c.preturi[i];
		}
		return in;

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
		this->titlu = new char[strlen("Anonim") + 1];
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

	const int& operator[](int idx) {
		if (idx >= 0 && idx < nrArticole)
			return titlu[idx];
		throw 404;
	}

	friend ostream& operator<< (ostream& out, const Articol articol) {
		out << "ID: " << articol.ID << endl;
		out << "Titlu: " << articol.titlu << "; " << endl;
		out << "Autor: " << articol.autor << "; " << endl;
		out << "An Publicare: " << articol.anPublicare << "; " << endl;
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Articol& articol) {
		cout << "Titlu: ";
		char aux[100];
		in >> aux;
		delete[] articol.titlu;
		articol.titlu = new char[strlen(aux) + 1];
		strcpy_s(articol.titlu, strlen(aux) + 1, aux);

		cout << "Autor: ";
		in >> articol.autor;
		cout << "An publicare: ";
		in >> articol.anPublicare;
		return in;

	}

	~Articol() {
		delete[] this->titlu;
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


class Revista {
private:
	string numeRevista;
	int anAparitie;
	float pretRevista;
	int nrArticole;
	Articol* Articole;

public:
	Revista() {
		this->numeRevista = "Educatie Express";
		this->anAparitie = 1998;
		this->pretRevista = 20;
		this->nrArticole = 10;
		this->Articole = new Articol[10];
	}

	Revista(const Revista& r) {
		this->numeRevista = r.numeRevista;
		this->anAparitie = r.anAparitie;
		this->pretRevista = r.pretRevista;
		this->nrArticole = r.nrArticole;
		this->Articole = new Articol[nrArticole];
		for (int i = 0; i < nrArticole; ++i) {
			this->Articole[i] = Articol();
		}

	};

	~Revista() {
		delete[] this->Articole;
	}

	Revista& operator=(const Revista& r) {
		if (this != &r) {
			this->numeRevista = r.numeRevista;
			this->anAparitie = r.anAparitie;
			this->pretRevista = r.pretRevista;
			this->nrArticole = r.nrArticole;
			if (this->Articole != NULL) {
				delete[]this->Articole;
			}

			this->Articole = new Articol[this->nrArticole];
			for (int i = 0; i < this->nrArticole; i++)
			{
				this->Articole[i] = r.Articole[i];
			}
		}
		return *this;
	}

	Articol& operator[](int index) {
		if (index >= 0 && index < this->nrArticole) {
			return this->Articole[index];
		}
	}

	Revista operator++() {
		this->pretRevista += 10;
		return *this;
	}

	string getNumeRevista() {
		return numeRevista;
	}
	void setNumeRevista(string numeRevista) {
		this->numeRevista = numeRevista;
	}

	int getAnAparitie() {
		return anAparitie;
	}
	void setAnAparitie(int anAparitie) {
		this->anAparitie = anAparitie;
	}

	float getPretRevista() {
		return pretRevista;
	}
	void setPretRevista() {
		this->pretRevista = pretRevista;
	}

	int getNrArticole() {
		return nrArticole;
	}
	void setNrArticole(int nrArticole) {
		this->nrArticole = nrArticole;
	}

	void afiseazaArticole() const {
		for (int i = 0; i < nrArticole; ++i) {
			cout << Articole[i];
		}
	}

	void afisare() {
		cout << "Revista '" << numeRevista << "' publicata in anul " << anAparitie << " are pretul de " << pretRevista << " lei si detine " << nrArticole << " articole.\n";
	}
};

class Reporter : public Jurnalist {
private:
	char* specializare;
	int nrPublicari;
public:
	Reporter() : Jurnalist() {
		this->nrPublicari = 30;
		this->specializare = new char[strlen("Politica") + 1];
		strcpy_s(this->specializare, strlen("Politica") + 1, "Politica");
	}

	Reporter(int nrPublicari, const char* specializare) : Jurnalist() {
		this->nrPublicari = nrPublicari;
		this->specializare = new char[strlen(specializare) + 1];
		strcpy_s(this->specializare, strlen(specializare) + 1, specializare);
	}

	Reporter(int nrPublicari, const char* specializare, const char* nume, string prenume, int varsta, float anexp) : Jurnalist(nume, prenume, varsta, anexp) {
		this->nrPublicari = nrPublicari;
		this->specializare = new char[strlen(specializare) + 1];
		strcpy_s(this->specializare, strlen(specializare) + 1, specializare);
	}
	Reporter(const Reporter& r) : Jurnalist(r) {
		this->nrPublicari = r.nrPublicari;
		this->specializare = new char[strlen(r.specializare) + 1];
		strcpy_s(this->specializare, strlen(r.specializare) + 1, r.specializare);
	}
	~Reporter() {
		if (this->specializare) {
			delete[]this->specializare;
		}
	}

	Reporter operator= (const Reporter& r) {
		if (this != &r) {
			Jurnalist :: operator=(r);
			this->nrPublicari = r.nrPublicari;
			if (this->specializare) {
				delete[] this->specializare;
			}
			this->specializare = new char[strlen(r.specializare) + 1];
			strcpy_s(this->specializare, strlen(r.specializare) + 1, r.specializare);
		}
		return *this;
	}

	
	string getPrenume(){
		return "Prenume: " + Jurnalist::getPrenume();
	}

	

	friend ostream& operator<<(ostream& ecran, const Reporter& r) {
		ecran << (Jurnalist)r;
		ecran << r.specializare << " ";
		ecran << r.nrPublicari << endl;
		return ecran;
	}

	friend istream& operator>>(istream& tast, Reporter& r) {
		tast >> (Jurnalist&)r;
		cout << "Numar Publicari:";
		tast >> r.nrPublicari;
		if (r.specializare)
		{
			delete[]r.specializare;
		}
		cout << "Denumire specializare:";
		char buffer[30];
		tast >> buffer;
		r.specializare = new char[strlen(buffer) + 1];
		strcpy_s(r.specializare, strlen(buffer) + 1, buffer);
		return tast;
	}
};

class ArticolPolitic : public Articol {
private:
	char* sursa;
	int nrComentarii;
public:
	ArticolPolitic() : Articol() {
		this->nrComentarii = 30;
		this->sursa = new char[strlen("TribunaUS") + 1];
		strcpy_s(this->sursa, strlen("TribunaUS") + 1, "TribunaUS");
	}

	ArticolPolitic(int nrComentarii, const char* sursa) : Articol() {
		this->nrComentarii = nrComentarii;
		this->sursa = new char[strlen(sursa) + 1];
		strcpy_s(this->sursa, strlen(sursa) + 1, sursa);
	}

	ArticolPolitic(int nrComentarii, const char* sursa, const char* titlu, string autor, int anPublicare) : Articol(titlu, autor, anPublicare) {
		this->nrComentarii = nrComentarii;
		this->sursa = new char[strlen(sursa) + 1];
		strcpy_s(this->sursa, strlen(sursa) + 1, sursa);
	}
	ArticolPolitic(const ArticolPolitic& ap) : Articol(ap) {
		this->nrComentarii = ap.nrComentarii;
		this->sursa = new char[strlen(ap.sursa) + 1];
		strcpy_s(this->sursa, strlen(ap.sursa) + 1, ap.sursa);
	}
	~ArticolPolitic() {
		if (this->sursa) {
			delete[]this->sursa;
		}
	}

	ArticolPolitic operator= (const ArticolPolitic& ap) {
		if (this != &ap) {
			Articol :: operator=(ap);
			this->nrComentarii = ap.nrComentarii;
			if (this->sursa) {
				delete[] this->sursa;
			}
			this->sursa = new char[strlen(ap.sursa) + 1];
			strcpy_s(this->sursa, strlen(ap.sursa) + 1, ap.sursa);
		}
		return *this;
	}

	friend ostream& operator<<(ostream& ecran, const ArticolPolitic& ap) {
		ecran << (Articol)ap;
		ecran << ap.sursa << " ";
		ecran << ap.nrComentarii << endl;
		return ecran;
	}

	friend istream& operator>>(istream& tast, ArticolPolitic& ap) {
		tast >> (Articol&)ap;
		cout << "Numar Comentarii:";
		tast >> ap.nrComentarii;
		if (ap.sursa)
		{
			delete[]ap.sursa;
		}
		cout << "Denumire sursa:";
		char buffer[30];
		tast >> buffer;
		ap.sursa = new char[strlen(buffer) + 1];
		strcpy_s(ap.sursa, strlen(buffer) + 1, buffer);
		return tast;
	}

};


int main() {
	
	Reporter rep1;
	rep1.afisare();



	Jurnalist j1;
	j1.afisare();

	j1 = rep1; ;

	cout << j1.getPrenume() << endl;
	cout << rep1.getPrenume() << endl;

	Reporter rep2 = rep1;
	Reporter rep3; 
	rep3 = rep1; 
	cout << rep1; 


	cout << endl;

	Jurnalist j2("Adriana", 19);
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
	cout << endl << endl;
	cout << "ID: " << j2.getID() << endl;
	cout << "Prenume: " << j2.getPrenume() << endl;
	cout << "Varsta: " << j2.getVarsta() << endl;
	cout << "An experienta: " << j2.getAnexp() << endl << endl;

	Jurnalist j3("Railean", "Dan", 22, 3);
	ofstream file("fisier.txt", ios::out);
	file << j3;
	j3.afisare();

	Jurnalist jCitit;
	ifstream fisIn("fisier.txt", ios::in);
	fisIn >> jCitit;
	cout << jCitit;

	cout << endl;
	Jurnalist j4(j3);
	j4.afisare();
	cout << endl << endl;

	j1 = j3;
	j1.afisare();
	cout << endl;


	if (j2 < j3) {
		cout << j2.getPrenume() << " este mai tanar decat " << j3.getPrenume() << endl;
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

	Jurnalist* jvector = new Jurnalist[3];
	jvector[0] = j3;
	jvector[1] = j1;
	jvector[2] = j2;

	for (int i = 0; i < 3; i++) {
		cout << jvector[i];
	}

	Jurnalist** jmatrice = new Jurnalist * [3];
	for (int i = 0; i < 3; i++) {
		jmatrice[i] = new Jurnalist[3];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << jmatrice[i][j];
		}
	}

	delete[]jmatrice;
	delete[]jvector;


	Jurnalist::AfisareNrJurnalisti();


	Camera c1;
	c1.afisare();

	Camera c2("Nikon", 4);
	c2.afisare();

	Camera c3("Sony", 3, new float[3] {1200, 1500, 1800});
	ofstream fileC("fisierc.txt", ios::out);
	fileC << c3;
	c3.afisare();
	cout << endl;
	cout << "Marca camerei: " << c3.getMarca() << endl;
	cout << "Numar de componente: " << c3.getNrComponente() << endl;

	Camera cCitit;
	ifstream fisInc("fisierc.txt", ios::in);
	fisInc >> cCitit;
	cout << cCitit;

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


	if (c1 != c2) {
		cout << "Camerele sunt diferite." << endl;
	}

	c1 = c3;
	c1.afisare();
	cout << endl;

	c1 = c5 + c3;
	c1.afisare();
	c6 = c5 - 15;
	cout << endl;
	c5.afisare();
	cout << endl;

	cout << c4 << endl;

	Camera::AfisareNrCamere();

	Camera* cvector = new Camera[3];
	cvector[0] = c3;
	cvector[1] = c1;
	cvector[2] = c5;

	for (int i = 0; i < 3; i++) {
		cout << cvector[i] << endl << endl;
	}

	cout << endl;

	Camera** cmatrice = new Camera * [3];
	for (int i = 0; i < 3; i++) {
		cmatrice[i] = new Camera[3];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cmatrice[i][j];
		}
	}

	//NU SE AFIS PRETURILE IN MATRICE????????

	delete[]cmatrice;
	delete[]cvector;

	cout << endl;


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
	cout << endl;

	a1 = a4;
	a1.afisare();


	Articol::AfisareNrArticole();

	ProcesareJurnalist(j2);
	ProcesareArticol(a3);
	cout << endl;

	Articol* avector = new Articol[3];
	avector[0] = a3;
	avector[1] = a1;
	avector[2] = a2;

	for (int i = 0; i < 3; i++) {
		cout << avector[i];
	}

	Articol** amatrice = new Articol * [3];
	for (int i = 0; i < 3; i++) {
		amatrice[i] = new Articol[3];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << amatrice[i][j];
		}
	}

	delete[]amatrice;
	delete[]avector;

	Revista r1;
	cin >> a1;
	cout << r1[0];
	r1[1] = a1;
	cout << r1[0];
	cout << ": " << r1[0][1] << endl;
	cout << r1[0].getTitlu();

	Revista r2(r1);
	r2.afisare();




	return 0;
}
