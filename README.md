# Merjenje nadmorske višine

### 1. Opis projekta
Ustvarila sva napravo za merjenje nadmorske višine. Uporabila sva senzor BME280, ki s pomočjo meritev temperature, vlage in tlaka prek programske kode izračuna nadmorsko višino. Na LCD-zaslonu se izpisujejo nadmorska višina ter vsi podatki, ki vplivajo na njen izračun (temperatura, vlaga in tlak).

### 2. Kosovnica
* Arduino UNO
* LCD 20x4
* BME280 senzor
* Stikalo za vklop/izklop
* Baterijski konektor
* Baterija
* Hitra sponka
* Povezovalne žičke

### 3. Vezalna shema
![Vezava](vezava_easyeda.png)

### 4. Načrt ohišja
![Ohišje](ohišje_Onshape.png)

### Pokrov
![Pokrov](pokrov_Onshape.png)

### 5. Izračuni in enačbe
Za izdelavo najine vezave nisva potrebovala komponent, ki bi potrebovale enačbe in izračune.

### 6. Videoposnetek delovanja

### 7. A-test
![Atest](a.test.jpg)

### 8. Komentar
Merilna naprava deluje stabilno in v skladu s pričakovanji, meja napake pa je v mejah normale. Meritve so bile opravljene, ko je bil zračni tlak približno 1022 hPa. Ker je bil zračni tlak v času kalibracije blizu standardne vrednosti, so izračuni nadmorske višine natančni. Z vezavo sva imela veliko težav, saj so se žičke večkrat staknile, zato sva težavo rešila tako, da sva uporabila večpinske konektorje za Arduino žičke. Težave sva imela tudi s povezovanjem ozemljitev (GND), kjer sva potrebovala originalno hitro sponko, da je vezava delovala, kot bi morala.

### 9. Izboljšave
Za izboljšavo merilnika nadmorske višine bi lahko dodala gumba za kalibracijo zračnega tlaka v realnem času, uvedla programsko glajenje podatkov z drsnim povprečjem ali napravo opremila z GPS modulom in MicroSD kartico za beleženje poti.
