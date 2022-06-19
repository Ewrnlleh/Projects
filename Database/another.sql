--
-- PostgreSQL database dump
--

-- Dumped from database version 12.1
-- Dumped by pg_dump version 12.1

-- Started on 2019-12-08 16:05:01

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 219 (class 1259 OID 17285)
-- Name: AdresBilgileri; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."AdresBilgileri" (
    "adresKodu" character varying NOT NULL,
    ulke character varying NOT NULL,
    sehir character varying NOT NULL,
    "ilce/eyalet" character varying,
    konum character varying
);


ALTER TABLE public."AdresBilgileri" OWNER TO postgres;

--
-- TOC entry 205 (class 1259 OID 16420)
-- Name: AracBaglanti; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."AracBaglanti" (
    "baglantiNumarasi" character(8) NOT NULL,
    "soruNumarasi" character varying NOT NULL
);


ALTER TABLE public."AracBaglanti" OWNER TO postgres;

--
-- TOC entry 211 (class 1259 OID 16467)
-- Name: AracBasarim; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."AracBasarim" (
    "basarimKodu" character(2) NOT NULL,
    "kullaniciKodu" character(5) NOT NULL
);


ALTER TABLE public."AracBasarim" OWNER TO postgres;

--
-- TOC entry 203 (class 1259 OID 16410)
-- Name: AracEtiket; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."AracEtiket" (
    "etiketAdi" character(8) NOT NULL,
    "soruNumarasi" character varying NOT NULL
);


ALTER TABLE public."AracEtiket" OWNER TO postgres;

--
-- TOC entry 204 (class 1259 OID 16415)
-- Name: BaglantiliSoru; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."BaglantiliSoru" (
    "baglantiNumarasi" character(8) NOT NULL,
    "baglantiDerecesi" real
);


ALTER TABLE public."BaglantiliSoru" OWNER TO postgres;

--
-- TOC entry 218 (class 1259 OID 17263)
-- Name: Basarim; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Basarim" (
    "basarimKodu" character(2) NOT NULL,
    "basarimDetaylari" text,
    "basarimBecerisi" character varying
);


ALTER TABLE public."Basarim" OWNER TO postgres;

--
-- TOC entry 208 (class 1259 OID 16435)
-- Name: Cevap; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Cevap" (
    "cevapNumarasi" character varying(5) NOT NULL,
    "cevapTarihi" date NOT NULL,
    "oySayisi" bigint,
    "cevapVeren" character varying NOT NULL,
    "soruNumarasi" character varying NOT NULL
);


ALTER TABLE public."Cevap" OWNER TO postgres;

--
-- TOC entry 207 (class 1259 OID 16430)
-- Name: CevaplanmamisSoru; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."CevaplanmamisSoru" (
    "siraNumarasi" character(3) NOT NULL,
    oy bigint
);


ALTER TABLE public."CevaplanmamisSoru" OWNER TO postgres;

--
-- TOC entry 216 (class 1259 OID 16501)
-- Name: Editor; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Editor" (
    "kullaniciKodu" character(5) NOT NULL,
    "duzeltmeSayisi" bigint,
    "kontrolSaati" bigint
);


ALTER TABLE public."Editor" OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 16677)
-- Name: Etiket; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Etiket" (
    "etiketAdi" character(8) NOT NULL,
    "kisaltmaAdi" character varying(16) NOT NULL,
    "etiketUzunlugu" smallint NOT NULL,
    konu text
);


ALTER TABLE public."Etiket" OWNER TO postgres;

--
-- TOC entry 206 (class 1259 OID 16425)
-- Name: Gundem; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Gundem" (
    "gundemNumarasi" character(3) NOT NULL,
    "gundemSirasi" smallint
);


ALTER TABLE public."Gundem" OWNER TO postgres;

--
-- TOC entry 210 (class 1259 OID 16451)
-- Name: Kullanici; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Kullanici" (
    "kullaniciKodu" character(5) NOT NULL,
    "kullaniciAdi" character varying NOT NULL
);


ALTER TABLE public."Kullanici" OWNER TO postgres;

--
-- TOC entry 209 (class 1259 OID 16443)
-- Name: Mesaj; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Mesaj" (
    "mesajKodu" character(3) NOT NULL,
    "gönderen" character varying NOT NULL,
    "mesajTarihi" date NOT NULL,
    "kullaniciKodu" character(5) NOT NULL
);


ALTER TABLE public."Mesaj" OWNER TO postgres;

--
-- TOC entry 202 (class 1259 OID 16397)
-- Name: Soru; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Soru" (
    "soruTarihi" date NOT NULL,
    "goruntulenmeSayisi" bigint,
    "kullaniciKodu" character(5) NOT NULL,
    "siraNumarasi" character(3),
    "gundemNumarasi" character(3),
    "soruNumarasi" character varying NOT NULL,
    detaylar text
);


ALTER TABLE public."Soru" OWNER TO postgres;

--
-- TOC entry 213 (class 1259 OID 16480)
-- Name: Uye; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Uye" (
    "uyeAdi" character varying NOT NULL,
    "kullaniciKodu" character(5) NOT NULL,
    "uyeResmi" character varying
);


ALTER TABLE public."Uye" OWNER TO postgres;

--
-- TOC entry 214 (class 1259 OID 16488)
-- Name: UyelikBilgileri; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."UyelikBilgileri" (
    "kullaniciKodu" character(5) NOT NULL,
    email character varying NOT NULL,
    "kayitTarihi" date NOT NULL,
    "iletiSayisi" bigint,
    "toplulukKaydi" character varying,
    itibar real,
    rozetler character varying,
    "adresKodu" character varying NOT NULL
);


ALTER TABLE public."UyelikBilgileri" OWNER TO postgres;

--
-- TOC entry 212 (class 1259 OID 16472)
-- Name: Yetkili; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Yetkili" (
    "kullaniciKodu" character(5) NOT NULL,
    "yetkiliAdi" character varying NOT NULL
);


ALTER TABLE public."Yetkili" OWNER TO postgres;

--
-- TOC entry 215 (class 1259 OID 16496)
-- Name: Yönetici; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Yönetici" (
    "kullaniciKodu" character(5) NOT NULL,
    "yönetimSaati" bigint
);


ALTER TABLE public."Yönetici" OWNER TO postgres;

--
-- TOC entry 2975 (class 0 OID 17285)
-- Dependencies: 219
-- Data for Name: AdresBilgileri; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."AdresBilgileri" ("adresKodu", ulke, sehir, "ilce/eyalet", konum) FROM stdin;
34f34g4qeh	Almanya	Frankfurt	Hanau	Hanau-Steinheim
1234	Fransa	Nantes	Clisson	Mairie de Clisson
125454erf	Pakistan	Multan	Nandla	\N
6547856gh	İtalya	Rome	\N	Kamptee
trh765	Amerika	Orlando	Florida	\N
\.


--
-- TOC entry 2961 (class 0 OID 16420)
-- Dependencies: 205
-- Data for Name: AracBaglanti; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."AracBaglanti" ("baglantiNumarasi", "soruNumarasi") FROM stdin;
35      	3
5       	3
15      	4
35      	5
60      	7
10      	6
\.


--
-- TOC entry 2967 (class 0 OID 16467)
-- Dependencies: 211
-- Data for Name: AracBasarim; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."AracBasarim" ("basarimKodu", "kullaniciKodu") FROM stdin;
43	q45h4
76	q45h4
4 	q45h4
8 	12314
43	8k78b
87	8k78b
\.


--
-- TOC entry 2959 (class 0 OID 16410)
-- Dependencies: 203
-- Data for Name: AracEtiket; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."AracEtiket" ("etiketAdi", "soruNumarasi") FROM stdin;
31e413fe	1
21r3htdf	1
21r3htdf	2
ytkjutek	4
31e413fe	7
r524t5rh	3
eher453t	3
21r3htdf	3
\.


--
-- TOC entry 2960 (class 0 OID 16415)
-- Dependencies: 204
-- Data for Name: BaglantiliSoru; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."BaglantiliSoru" ("baglantiNumarasi", "baglantiDerecesi") FROM stdin;
1       	154
3       	1000
5       	245
35      	450
15      	2500
60      	\N
10      	800
\.


--
-- TOC entry 2974 (class 0 OID 17263)
-- Dependencies: 218
-- Data for Name: Basarim; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Basarim" ("basarimKodu", "basarimDetaylari", "basarimBecerisi") FROM stdin;
12	Become an Ubuntu Member	Ubuntu
43	Register on Launchpad	register
76	Get a 'Legandary' badge on AskUbuntu	badge
4 	\N	\N
87	Change your wallpaper	\N
8 	Report a bug in Ubuntu	Report
\.


--
-- TOC entry 2964 (class 0 OID 16435)
-- Dependencies: 208
-- Data for Name: Cevap; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Cevap" ("cevapNumarasi", "cevapTarihi", "oySayisi", "cevapVeren", "soruNumarasi") FROM stdin;
1	2019-08-07	78	Max Zalinko	3
2	2018-03-20	8	MacBook1	4
10	2018-08-06	66	CP CHAN	3
23	2016-03-07	2360	Rodrigo Belli	7
76	2013-12-19	800	Adam	1
100	2018-02-25	32	gelonida	7
\.


--
-- TOC entry 2963 (class 0 OID 16430)
-- Dependencies: 207
-- Data for Name: CevaplanmamisSoru; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."CevaplanmamisSoru" ("siraNumarasi", oy) FROM stdin;
1  	165
23 	256
109	1000
2  	43
4  	2345
67 	23
\.


--
-- TOC entry 2972 (class 0 OID 16501)
-- Dependencies: 216
-- Data for Name: Editor; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Editor" ("kullaniciKodu", "duzeltmeSayisi", "kontrolSaati") FROM stdin;
23r32	340	600
24565	56	100
\.


--
-- TOC entry 2973 (class 0 OID 16677)
-- Dependencies: 217
-- Data for Name: Etiket; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Etiket" ("etiketAdi", "kisaltmaAdi", "etiketUzunlugu", konu) FROM stdin;
31e413fe	Ubuntu	6	What is Ubuntu?
21r3htdf	wireless	8	Ubuntu 18.04 Connected to Wi-Fi but no internet?
r524t5rh	timestamp	10	Changing Time
eher453t	reboot	6	\N
ytkjutek	18.04	5	Ubuntu Version
\.


--
-- TOC entry 2962 (class 0 OID 16425)
-- Dependencies: 206
-- Data for Name: Gundem; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Gundem" ("gundemNumarasi", "gundemSirasi") FROM stdin;
213	1
6  	2
987	3
65 	7
546	9
89 	10
\.


--
-- TOC entry 2966 (class 0 OID 16451)
-- Dependencies: 210
-- Data for Name: Kullanici; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Kullanici" ("kullaniciKodu", "kullaniciAdi") FROM stdin;
q45h4	zou hai
q4h55	Michael
12e1f	Bri
12314	BobRun
8k78b	Jonathan
23r32	Manager
24565	editor22
\.


--
-- TOC entry 2965 (class 0 OID 16443)
-- Dependencies: 209
-- Data for Name: Mesaj; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Mesaj" ("mesajKodu", "gönderen", "mesajTarihi", "kullaniciKodu") FROM stdin;
123	Gavin Crawford	2018-03-07	q45h4
435	Manager	2018-12-03	12e1f
2  	Manager	2019-12-24	8k78b
34 	Dennis	2015-03-15	12314
\.


--
-- TOC entry 2958 (class 0 OID 16397)
-- Dependencies: 202
-- Data for Name: Soru; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Soru" ("soruTarihi", "goruntulenmeSayisi", "kullaniciKodu", "siraNumarasi", "gundemNumarasi", "soruNumarasi", detaylar) FROM stdin;
2016-03-24	123	12e1f	4  	213	1	enter image description here I was trying to change my update settings 
2017-08-20	\N	12e1f	\N	89 	2	But it looks like, the package was long ago removed from the repository
2019-02-05	1090	12e1f	1  	\N	3	\N
2019-02-07	\N	12314	\N	6  	4	I then made some changes, such as the time zone, language input, wifi setup, etc
2016-11-10	29374	8k78b	23 	\N	5	\N
2013-08-09	23	8k78b	\N	65 	6	Okay, so this has probably been asked time and time again but I genuinely need some advice
2016-01-23	2346	12e1f	2  	546	7	this are numbers 12345 this letters abc def ghi Let's say
2017-07-19	801	q4h55	109	\N	8	I'm using Ubuntu 19.10 with GNOME Terminal 3.34.2
\.


--
-- TOC entry 2969 (class 0 OID 16480)
-- Dependencies: 213
-- Data for Name: Uye; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Uye" ("uyeAdi", "kullaniciKodu", "uyeResmi") FROM stdin;
Haimato	q45h4	\N
Michael	q4h55	\N
Bryson	12e1f	\N
Bob Ross	12314	\N
Jonathan	8k78b	\N
\.


--
-- TOC entry 2970 (class 0 OID 16488)
-- Dependencies: 214
-- Data for Name: UyelikBilgileri; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."UyelikBilgileri" ("kullaniciKodu", email, "kayitTarihi", "iletiSayisi", "toplulukKaydi", itibar, rozetler, "adresKodu") FROM stdin;
q45h4	haim123@hotmail.com	2015-05-23	1060	29	10000	120	125454erf
q4h55	142michjael_fw@hotmail.com	2010-08-07	980	10	2500	56	1234
12e1f	bry99_21@gmail.com	2012-06-30	345	\N	2000	15	6547856gh
12314	BobRoss1@hotmail.com	2012-09-24	568	9	\N	60	trh765
8k78b	Jona2?@gmail.com	2014-01-13	\N	13	3000	32	34f34g4qeh
\.


--
-- TOC entry 2968 (class 0 OID 16472)
-- Dependencies: 212
-- Data for Name: Yetkili; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Yetkili" ("kullaniciKodu", "yetkiliAdi") FROM stdin;
23r32	John
24565	Peter
\.


--
-- TOC entry 2971 (class 0 OID 16496)
-- Dependencies: 215
-- Data for Name: Yönetici; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Yönetici" ("kullaniciKodu", "yönetimSaati") FROM stdin;
23r32	2390
\.


--
-- TOC entry 2814 (class 2606 OID 17292)
-- Name: AdresBilgileri AdresBilgileri_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AdresBilgileri"
    ADD CONSTRAINT "AdresBilgileri_pkey" PRIMARY KEY ("adresKodu");


--
-- TOC entry 2777 (class 2606 OID 16932)
-- Name: AracBaglanti AracBaglanti_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AracBaglanti"
    ADD CONSTRAINT "AracBaglanti_pkey" PRIMARY KEY ("baglantiNumarasi", "soruNumarasi");


--
-- TOC entry 2793 (class 2606 OID 17272)
-- Name: AracBasarim AracBasarim_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AracBasarim"
    ADD CONSTRAINT "AracBasarim_pkey" PRIMARY KEY ("basarimKodu", "kullaniciKodu");


--
-- TOC entry 2771 (class 2606 OID 16912)
-- Name: AracEtiket AracEtiket_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AracEtiket"
    ADD CONSTRAINT "AracEtiket_pkey" PRIMARY KEY ("etiketAdi", "soruNumarasi");


--
-- TOC entry 2775 (class 2606 OID 16715)
-- Name: BaglantiliSoru BaglantiliSoru_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."BaglantiliSoru"
    ADD CONSTRAINT "BaglantiliSoru_pkey" PRIMARY KEY ("baglantiNumarasi");


--
-- TOC entry 2812 (class 2606 OID 17270)
-- Name: Basarim Basarim_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Basarim"
    ADD CONSTRAINT "Basarim_pkey" PRIMARY KEY ("basarimKodu");


--
-- TOC entry 2785 (class 2606 OID 17356)
-- Name: Cevap Cevap_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Cevap"
    ADD CONSTRAINT "Cevap_pkey" PRIMARY KEY ("cevapNumarasi");


--
-- TOC entry 2783 (class 2606 OID 16772)
-- Name: CevaplanmamisSoru CevaplanmamisSoru_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."CevaplanmamisSoru"
    ADD CONSTRAINT "CevaplanmamisSoru_pkey" PRIMARY KEY ("siraNumarasi");


--
-- TOC entry 2808 (class 2606 OID 17185)
-- Name: Editor Editor_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Editor"
    ADD CONSTRAINT "Editor_pkey" PRIMARY KEY ("kullaniciKodu");


--
-- TOC entry 2810 (class 2606 OID 16684)
-- Name: Etiket Etiket_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Etiket"
    ADD CONSTRAINT "Etiket_pkey" PRIMARY KEY ("etiketAdi");


--
-- TOC entry 2781 (class 2606 OID 16753)
-- Name: Gundem Gundem_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Gundem"
    ADD CONSTRAINT "Gundem_pkey" PRIMARY KEY ("gundemNumarasi");


--
-- TOC entry 2791 (class 2606 OID 17215)
-- Name: Kullanici Kullanici_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici"
    ADD CONSTRAINT "Kullanici_pkey" PRIMARY KEY ("kullaniciKodu");


--
-- TOC entry 2788 (class 2606 OID 17309)
-- Name: Mesaj Mesaj_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Mesaj"
    ADD CONSTRAINT "Mesaj_pkey" PRIMARY KEY ("mesajKodu");


--
-- TOC entry 2766 (class 2606 OID 16885)
-- Name: Soru Soru_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Soru"
    ADD CONSTRAINT "Soru_pkey" PRIMARY KEY ("soruNumarasi");


--
-- TOC entry 2799 (class 2606 OID 17153)
-- Name: Uye Uye_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Uye"
    ADD CONSTRAINT "Uye_pkey" PRIMARY KEY ("uyeAdi", "kullaniciKodu");


--
-- TOC entry 2802 (class 2606 OID 17198)
-- Name: UyelikBilgileri UyelikBilgileri_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."UyelikBilgileri"
    ADD CONSTRAINT "UyelikBilgileri_pkey" PRIMARY KEY ("kullaniciKodu", email);


--
-- TOC entry 2797 (class 2606 OID 17137)
-- Name: Yetkili Yetkili_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Yetkili"
    ADD CONSTRAINT "Yetkili_pkey" PRIMARY KEY ("kullaniciKodu");


--
-- TOC entry 2806 (class 2606 OID 17171)
-- Name: Yönetici Yonetici_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Yönetici"
    ADD CONSTRAINT "Yonetici_pkey" PRIMARY KEY ("kullaniciKodu");


--
-- TOC entry 2778 (class 1259 OID 16849)
-- Name: fki_AracBaglanti_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_AracBaglanti_fkey" ON public."AracBaglanti" USING btree ("baglantiNumarasi");


--
-- TOC entry 2794 (class 1259 OID 17273)
-- Name: fki_AracBasarim_basarimKodu_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_AracBasarim_basarimKodu_fkey" ON public."AracBasarim" USING btree ("basarimKodu");


--
-- TOC entry 2795 (class 1259 OID 17122)
-- Name: fki_AracBasarim_kullaniciKodu_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_AracBasarim_kullaniciKodu_fkey" ON public."AracBasarim" USING btree ("kullaniciKodu");


--
-- TOC entry 2772 (class 1259 OID 16878)
-- Name: fki_AracEtiket_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_AracEtiket_fkey" ON public."AracEtiket" USING btree ("etiketAdi");


--
-- TOC entry 2773 (class 1259 OID 16913)
-- Name: fki_AracEtiket_soruNumarasi_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_AracEtiket_soruNumarasi_fkey" ON public."AracEtiket" USING btree ("soruNumarasi");


--
-- TOC entry 2786 (class 1259 OID 17330)
-- Name: fki_Cevap_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_Cevap_fkey" ON public."Cevap" USING btree ("soruNumarasi");


--
-- TOC entry 2789 (class 1259 OID 17086)
-- Name: fki_Mesaj_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_Mesaj_fkey" ON public."Mesaj" USING btree ("kullaniciKodu");


--
-- TOC entry 2767 (class 1259 OID 17318)
-- Name: fki_Soru_gündemNumarasi_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_Soru_gündemNumarasi_fkey" ON public."Soru" USING btree ("gundemNumarasi");


--
-- TOC entry 2768 (class 1259 OID 17102)
-- Name: fki_Soru_kullaniciKodu_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_Soru_kullaniciKodu_fkey" ON public."Soru" USING btree ("kullaniciKodu");


--
-- TOC entry 2769 (class 1259 OID 17324)
-- Name: fki_Soru_siraNumarasi_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_Soru_siraNumarasi_fkey" ON public."Soru" USING btree ("siraNumarasi");


--
-- TOC entry 2800 (class 1259 OID 17154)
-- Name: fki_Uye_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_Uye_fkey" ON public."Uye" USING btree ("kullaniciKodu");


--
-- TOC entry 2803 (class 1259 OID 17381)
-- Name: fki_UyelikBilgileri_adresKodu_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_UyelikBilgileri_adresKodu_fkey" ON public."UyelikBilgileri" USING btree ("adresKodu");


--
-- TOC entry 2804 (class 1259 OID 17199)
-- Name: fki_UyelikBilgileri_kullaniciKodu_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_UyelikBilgileri_kullaniciKodu_fkey" ON public."UyelikBilgileri" USING btree ("kullaniciKodu");


--
-- TOC entry 2779 (class 1259 OID 16933)
-- Name: fki_asd; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX fki_asd ON public."AracBaglanti" USING btree ("soruNumarasi");


--
-- TOC entry 2820 (class 2606 OID 16850)
-- Name: AracBaglanti AracBaglanti_baglantiNumarasi_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AracBaglanti"
    ADD CONSTRAINT "AracBaglanti_baglantiNumarasi_fkey" FOREIGN KEY ("baglantiNumarasi") REFERENCES public."BaglantiliSoru"("baglantiNumarasi");


--
-- TOC entry 2821 (class 2606 OID 16934)
-- Name: AracBaglanti AracBaglanti_soruNumarasi_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AracBaglanti"
    ADD CONSTRAINT "AracBaglanti_soruNumarasi_fkey" FOREIGN KEY ("soruNumarasi") REFERENCES public."Soru"("soruNumarasi");


--
-- TOC entry 2825 (class 2606 OID 17280)
-- Name: AracBasarim AracBasarim_basarimKodu_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AracBasarim"
    ADD CONSTRAINT "AracBasarim_basarimKodu_fkey" FOREIGN KEY ("basarimKodu") REFERENCES public."Basarim"("basarimKodu");


--
-- TOC entry 2824 (class 2606 OID 17226)
-- Name: AracBasarim AracBasarim_kullaniciKodu_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AracBasarim"
    ADD CONSTRAINT "AracBasarim_kullaniciKodu_fkey" FOREIGN KEY ("kullaniciKodu") REFERENCES public."Kullanici"("kullaniciKodu");


--
-- TOC entry 2818 (class 2606 OID 16879)
-- Name: AracEtiket AracEtiket_etiketAdi_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AracEtiket"
    ADD CONSTRAINT "AracEtiket_etiketAdi_fkey" FOREIGN KEY ("etiketAdi") REFERENCES public."Etiket"("etiketAdi");


--
-- TOC entry 2819 (class 2606 OID 16914)
-- Name: AracEtiket AracEtiket_soruNumarasi_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AracEtiket"
    ADD CONSTRAINT "AracEtiket_soruNumarasi_fkey" FOREIGN KEY ("soruNumarasi") REFERENCES public."Soru"("soruNumarasi");


--
-- TOC entry 2822 (class 2606 OID 17331)
-- Name: Cevap Cevap_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Cevap"
    ADD CONSTRAINT "Cevap_fkey" FOREIGN KEY ("soruNumarasi") REFERENCES public."Soru"("soruNumarasi");


--
-- TOC entry 2831 (class 2606 OID 17246)
-- Name: Editor Editor_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Editor"
    ADD CONSTRAINT "Editor_fkey" FOREIGN KEY ("kullaniciKodu") REFERENCES public."Kullanici"("kullaniciKodu");


--
-- TOC entry 2823 (class 2606 OID 17216)
-- Name: Mesaj Mesaj_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Mesaj"
    ADD CONSTRAINT "Mesaj_fkey" FOREIGN KEY ("kullaniciKodu") REFERENCES public."Kullanici"("kullaniciKodu");


--
-- TOC entry 2816 (class 2606 OID 17319)
-- Name: Soru Soru_gündemNumarasi_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Soru"
    ADD CONSTRAINT "Soru_gündemNumarasi_fkey" FOREIGN KEY ("gundemNumarasi") REFERENCES public."Gundem"("gundemNumarasi");


--
-- TOC entry 2815 (class 2606 OID 17221)
-- Name: Soru Soru_kullaniciKodu_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Soru"
    ADD CONSTRAINT "Soru_kullaniciKodu_fkey" FOREIGN KEY ("kullaniciKodu") REFERENCES public."Kullanici"("kullaniciKodu");


--
-- TOC entry 2817 (class 2606 OID 17325)
-- Name: Soru Soru_siraNumarasi_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Soru"
    ADD CONSTRAINT "Soru_siraNumarasi_fkey" FOREIGN KEY ("siraNumarasi") REFERENCES public."CevaplanmamisSoru"("siraNumarasi");


--
-- TOC entry 2827 (class 2606 OID 17236)
-- Name: Uye Uye_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Uye"
    ADD CONSTRAINT "Uye_fkey" FOREIGN KEY ("kullaniciKodu") REFERENCES public."Kullanici"("kullaniciKodu");


--
-- TOC entry 2829 (class 2606 OID 17376)
-- Name: UyelikBilgileri UyelikBilgileri_adresKodu_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."UyelikBilgileri"
    ADD CONSTRAINT "UyelikBilgileri_adresKodu_fkey" FOREIGN KEY ("adresKodu") REFERENCES public."AdresBilgileri"("adresKodu");


--
-- TOC entry 2828 (class 2606 OID 17251)
-- Name: UyelikBilgileri UyelikBilgileri_kullaniciKodu_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."UyelikBilgileri"
    ADD CONSTRAINT "UyelikBilgileri_kullaniciKodu_fkey" FOREIGN KEY ("kullaniciKodu") REFERENCES public."Kullanici"("kullaniciKodu");


--
-- TOC entry 2826 (class 2606 OID 17231)
-- Name: Yetkili Yetkili_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Yetkili"
    ADD CONSTRAINT "Yetkili_fkey" FOREIGN KEY ("kullaniciKodu") REFERENCES public."Kullanici"("kullaniciKodu");


--
-- TOC entry 2830 (class 2606 OID 17241)
-- Name: Yönetici Yonetici_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Yönetici"
    ADD CONSTRAINT "Yonetici_fkey" FOREIGN KEY ("kullaniciKodu") REFERENCES public."Kullanici"("kullaniciKodu");


-- Completed on 2019-12-08 16:05:01

--
-- PostgreSQL database dump complete
--

