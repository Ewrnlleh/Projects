--
-- PostgreSQL database dump
--

-- Dumped from database version 12.1
-- Dumped by pg_dump version 12.1

-- Started on 2019-12-16 17:27:21

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

--
-- TOC entry 217 (class 1255 OID 17536)
-- Name: ekle(character varying, character varying, character, text, character); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.ekle(_adi character varying, _soyadi character varying, _cinsiyeti character, _detaylar text, _kisitipkodu character) RETURNS integer
    LANGUAGE plpgsql
    AS $$
begin
	insert into "Kisi"
	(
		adi,
		soyadi,
	    cinsiyeti,
		detaylar,
		kisiTipKodu
	) values
	(
		_adi,
		_soyadi,
	    _cinsiyeti,
		_detaylar,
		_kisiTipKodu
	);
	if found then
		return 1;
	else
		return 0;
	end if;
end
$$;


ALTER FUNCTION public.ekle(_adi character varying, _soyadi character varying, _cinsiyeti character, _detaylar text, _kisitipkodu character) OWNER TO postgres;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 204 (class 1259 OID 17397)
-- Name: Adres; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Adres" (
    adres_id smallint NOT NULL,
    ulke character varying NOT NULL,
    sehir character varying NOT NULL,
    "adresDetayları" text
);


ALTER TABLE public."Adres" OWNER TO postgres;

--
-- TOC entry 211 (class 1259 OID 17465)
-- Name: Aile; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Aile" (
    aile_id character(3) NOT NULL,
    "aileSorumlusu_id" smallint,
    "aileAdı" character varying
);


ALTER TABLE public."Aile" OWNER TO postgres;

--
-- TOC entry 210 (class 1259 OID 17460)
-- Name: AileUyesi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."AileUyesi" (
    kisi_id smallint NOT NULL,
    aile_id character(3) NOT NULL
);


ALTER TABLE public."AileUyesi" OWNER TO postgres;

--
-- TOC entry 207 (class 1259 OID 17418)
-- Name: AracDosya; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."AracDosya" (
    kisi_id smallint NOT NULL,
    dosya_id smallint NOT NULL
);


ALTER TABLE public."AracDosya" OWNER TO postgres;

--
-- TOC entry 209 (class 1259 OID 17428)
-- Name: Dosya; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Dosya" (
    dosya_id smallint NOT NULL,
    "dosyaIcerigi" text NOT NULL,
    "olusturulmaTarihi" date NOT NULL,
    "guncellemeTarihi" date NOT NULL,
    "digerDetaylar" text,
    "dosyaTipKodu" "char"
);


ALTER TABLE public."Dosya" OWNER TO postgres;

--
-- TOC entry 208 (class 1259 OID 17423)
-- Name: DosyaTipi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."DosyaTipi" (
    "dosyaTipKodu" "char" NOT NULL,
    "dosyaTipAciklamasi" character(8) NOT NULL
);


ALTER TABLE public."DosyaTipi" OWNER TO postgres;

--
-- TOC entry 202 (class 1259 OID 17384)
-- Name: Kisi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Kisi" (
    kisi_id smallint NOT NULL,
    adi character varying NOT NULL,
    soyadi character varying NOT NULL,
    cinsiyeti "char" NOT NULL,
    detaylar text,
    "kisiTipKodu" "char",
    adres_id smallint,
    kurum_id smallint
);


ALTER TABLE public."Kisi" OWNER TO postgres;

--
-- TOC entry 212 (class 1259 OID 17504)
-- Name: Ebeveyn; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Ebeveyn" (
    gorevi character varying
)
INHERITS (public."Kisi");


ALTER TABLE public."Ebeveyn" OWNER TO postgres;

--
-- TOC entry 203 (class 1259 OID 17392)
-- Name: KisiTipi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."KisiTipi" (
    "kisiTipKodu" "char" NOT NULL,
    "kisiTipAcıklaması" character(9) NOT NULL
);


ALTER TABLE public."KisiTipi" OWNER TO postgres;

--
-- TOC entry 206 (class 1259 OID 17410)
-- Name: Kurum; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Kurum" (
    kurum_id smallint NOT NULL,
    "kurumAdi" character varying NOT NULL,
    "kurumTipKodu" character(2),
    adres_id smallint
);


ALTER TABLE public."Kurum" OWNER TO postgres;

--
-- TOC entry 205 (class 1259 OID 17405)
-- Name: KurumTipi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."KurumTipi" (
    "kurumTipKodu" character(2) NOT NULL,
    "kurumTip" character varying(20) NOT NULL
);


ALTER TABLE public."KurumTipi" OWNER TO postgres;

--
-- TOC entry 216 (class 1259 OID 17528)
-- Name: Odev; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Odev" (
    "not" character(3),
    dersadi character varying,
    digerdetaylar text
)
INHERITS (public."Dosya");


ALTER TABLE public."Odev" OWNER TO postgres;

--
-- TOC entry 213 (class 1259 OID 17510)
-- Name: Ogrenci; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Ogrenci" (
    sinifi character(2) NOT NULL,
    dogumtarihi date NOT NULL,
    "digerOgrencidetaylari" text
)
INHERITS (public."Kisi");


ALTER TABLE public."Ogrenci" OWNER TO postgres;

--
-- TOC entry 214 (class 1259 OID 17516)
-- Name: Ogretmen; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Ogretmen" (
    "görevi" character varying
)
INHERITS (public."Kisi");


ALTER TABLE public."Ogretmen" OWNER TO postgres;

--
-- TOC entry 215 (class 1259 OID 17522)
-- Name: Rapor; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Rapor" (
    rapordetaylari text
)
INHERITS (public."Dosya");


ALTER TABLE public."Rapor" OWNER TO postgres;

--
-- TOC entry 2900 (class 0 OID 17397)
-- Dependencies: 204
-- Data for Name: Adres; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Adres" (adres_id, ulke, sehir, "adresDetayları") FROM stdin;
\.


--
-- TOC entry 2907 (class 0 OID 17465)
-- Dependencies: 211
-- Data for Name: Aile; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Aile" (aile_id, "aileSorumlusu_id", "aileAdı") FROM stdin;
\.


--
-- TOC entry 2906 (class 0 OID 17460)
-- Dependencies: 210
-- Data for Name: AileUyesi; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."AileUyesi" (kisi_id, aile_id) FROM stdin;
\.


--
-- TOC entry 2903 (class 0 OID 17418)
-- Dependencies: 207
-- Data for Name: AracDosya; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."AracDosya" (kisi_id, dosya_id) FROM stdin;
\.


--
-- TOC entry 2905 (class 0 OID 17428)
-- Dependencies: 209
-- Data for Name: Dosya; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Dosya" (dosya_id, "dosyaIcerigi", "olusturulmaTarihi", "guncellemeTarihi", "digerDetaylar", "dosyaTipKodu") FROM stdin;
\.


--
-- TOC entry 2904 (class 0 OID 17423)
-- Dependencies: 208
-- Data for Name: DosyaTipi; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."DosyaTipi" ("dosyaTipKodu", "dosyaTipAciklamasi") FROM stdin;
\.


--
-- TOC entry 2908 (class 0 OID 17504)
-- Dependencies: 212
-- Data for Name: Ebeveyn; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Ebeveyn" (kisi_id, adi, soyadi, cinsiyeti, detaylar, "kisiTipKodu", adres_id, kurum_id, gorevi) FROM stdin;
\.


--
-- TOC entry 2898 (class 0 OID 17384)
-- Dependencies: 202
-- Data for Name: Kisi; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Kisi" (kisi_id, adi, soyadi, cinsiyeti, detaylar, "kisiTipKodu", adres_id, kurum_id) FROM stdin;
\.


--
-- TOC entry 2899 (class 0 OID 17392)
-- Dependencies: 203
-- Data for Name: KisiTipi; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."KisiTipi" ("kisiTipKodu", "kisiTipAcıklaması") FROM stdin;
\.


--
-- TOC entry 2902 (class 0 OID 17410)
-- Dependencies: 206
-- Data for Name: Kurum; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Kurum" (kurum_id, "kurumAdi", "kurumTipKodu", adres_id) FROM stdin;
\.


--
-- TOC entry 2901 (class 0 OID 17405)
-- Dependencies: 205
-- Data for Name: KurumTipi; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."KurumTipi" ("kurumTipKodu", "kurumTip") FROM stdin;
\.


--
-- TOC entry 2912 (class 0 OID 17528)
-- Dependencies: 216
-- Data for Name: Odev; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Odev" (dosya_id, "dosyaIcerigi", "olusturulmaTarihi", "guncellemeTarihi", "digerDetaylar", "dosyaTipKodu", "not", dersadi, digerdetaylar) FROM stdin;
\.


--
-- TOC entry 2909 (class 0 OID 17510)
-- Dependencies: 213
-- Data for Name: Ogrenci; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Ogrenci" (kisi_id, adi, soyadi, cinsiyeti, detaylar, "kisiTipKodu", adres_id, kurum_id, sinifi, dogumtarihi, "digerOgrencidetaylari") FROM stdin;
\.


--
-- TOC entry 2910 (class 0 OID 17516)
-- Dependencies: 214
-- Data for Name: Ogretmen; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Ogretmen" (kisi_id, adi, soyadi, cinsiyeti, detaylar, "kisiTipKodu", adres_id, kurum_id, "görevi") FROM stdin;
\.


--
-- TOC entry 2911 (class 0 OID 17522)
-- Dependencies: 215
-- Data for Name: Rapor; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Rapor" (dosya_id, "dosyaIcerigi", "olusturulmaTarihi", "guncellemeTarihi", "digerDetaylar", "dosyaTipKodu", rapordetaylari) FROM stdin;
\.


--
-- TOC entry 2757 (class 2606 OID 17404)
-- Name: Adres Adres_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Adres"
    ADD CONSTRAINT "Adres_pkey" PRIMARY KEY (adres_id);


--
-- TOC entry 2769 (class 2606 OID 17464)
-- Name: AileUyesi AileUyesi_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AileUyesi"
    ADD CONSTRAINT "AileUyesi_pkey" PRIMARY KEY (kisi_id, aile_id);


--
-- TOC entry 2771 (class 2606 OID 17472)
-- Name: Aile Aile_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Aile"
    ADD CONSTRAINT "Aile_pkey" PRIMARY KEY (aile_id);


--
-- TOC entry 2763 (class 2606 OID 17422)
-- Name: AracDosya AracDosya_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."AracDosya"
    ADD CONSTRAINT "AracDosya_pkey" PRIMARY KEY (kisi_id, dosya_id);


--
-- TOC entry 2765 (class 2606 OID 17427)
-- Name: DosyaTipi DosyaTipi_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."DosyaTipi"
    ADD CONSTRAINT "DosyaTipi_pkey" PRIMARY KEY ("dosyaTipKodu");


--
-- TOC entry 2767 (class 2606 OID 17435)
-- Name: Dosya Dosya_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Dosya"
    ADD CONSTRAINT "Dosya_pkey" PRIMARY KEY (dosya_id);


--
-- TOC entry 2755 (class 2606 OID 17396)
-- Name: KisiTipi KisiTipi_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KisiTipi"
    ADD CONSTRAINT "KisiTipi_pkey" PRIMARY KEY ("kisiTipKodu");


--
-- TOC entry 2753 (class 2606 OID 17391)
-- Name: Kisi Kisi_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kisi"
    ADD CONSTRAINT "Kisi_pkey" PRIMARY KEY (kisi_id);


--
-- TOC entry 2759 (class 2606 OID 17409)
-- Name: KurumTipi KurumTipi_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KurumTipi"
    ADD CONSTRAINT "KurumTipi_pkey" PRIMARY KEY ("kurumTipKodu");


--
-- TOC entry 2761 (class 2606 OID 17417)
-- Name: Kurum Kurum_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kurum"
    ADD CONSTRAINT "Kurum_pkey" PRIMARY KEY (kurum_id);


-- Completed on 2019-12-16 17:27:21

--
-- PostgreSQL database dump complete
--

