# Preface

Filename: industry-grc-reference.md
Creation date: 2026-09-30

Notes: This doc is 100% made with Claude AI and hasn't been post-edited. I saved it to use the category list as a framework for software development in my college classes. I wouldn't take the matrix with the employment outlook below too seriously. If you ask, I can send you the original Claude thread.
TLDR: AI-generated
---

# GRC Industry Reference: Regulations, Standards, Frameworks, and Dev Stacks

Compiled for choosing a target industry to frame college software projects around governance, risk, and compliance (GRC). Twenty industries are profiled, followed by a comparison matrix and a list of date-sensitive items to verify.

**How to read this:** each profile covers Regulations, Standards, Frameworks and platforms, Dev stacks, Process and compliance, Student-project feasibility, and a Key insight. Scores in the matrix are my subjective judgments, not measured data. All content was written from general knowledge without live source checks, so verify anything dated before citing it in coursework (see Part 3).

---

## Part 1: Comparison Matrix

### Scoring key (1 to 5)

| Column | Meaning |
|---|---|
| **Process weight** | How heavy the documentation and evidence burden is. 5 = very heavy. Informational only, not in the total. Heavy means more to demonstrate and more work. |
| **Standards access** | How much of the material is free or easy to obtain. 5 = mostly free. |
| **Embedded/systems fit** | Fit with embedded, low-level, real-time, and game/simulation skills. 5 = direct. |
| **Hiring demand** | Demand for developers who understand compliance in this area. 5 = high. |
| **Entry openness** | Absence of barriers such as clearance or citizenship. 5 = open to anyone. |
| **Score** | Standards access + Embedded fit + Hiring demand + Entry openness (max 20). |

### Matrix (sorted by score)

| Rank | Industry | Process weight | Standards access | Embedded/systems fit | Hiring demand | Entry openness | Score |
|---|---|---|---|---|---|---|---|
| 1 | Healthcare: Medical Equipment and Tech | 5 | 4 | 5 | 5 | 5 | **19** |
| 2 | Automotive (road vehicles, SDV) | 5 | 3 | 5 | 5 | 5 | **18** |
| 3 | Healthcare: General | 4 | 4 | 3 | 5 | 5 | **17** |
| 3 | Fintech: Digital Payments and Transfers | 3 | 4 | 3 | 5 | 5 | **17** |
| 3 | Fintech: Investing | 3 | 4 | 4 | 4 | 5 | **17** |
| 3 | Agriculture: Sustainable Farming | 2 | 5 | 4 | 3 | 5 | **17** |
| 3 | Agriculture: Food Safety | 3 | 5 | 4 | 3 | 5 | **17** |
| 8 | Aviation: Commercial Flights | 5 | 3 | 5 | 4 | 4 | **16** |
| 8 | Fintech: Insurance | 2 | 5 | 2 | 4 | 5 | **16** |
| 8 | National Security: Emergency Management | 3 | 5 | 3 | 4 | 4 | **16** |
| 8 | Healthcare: Public Health Emergencies | 3 | 5 | 3 | 3 | 5 | **16** |
| 12 | Healthcare: Public Health | 2 | 5 | 2 | 3 | 5 | **15** |
| 12 | Aviation: Shipping (Air Cargo) | 3 | 4 | 3 | 3 | 5 | **15** |
| 12 | Law Enforcement: Cybercrime | 3 | 4 | 4 | 4 | 3 | **15** |
| 12 | Emergency Services: Fire and Rescue | 4 | 3 | 5 | 2 | 5 | **15** |
| 12 | Emergency Services: HAZMAT | 4 | 4 | 4 | 2 | 5 | **15** |
| 17 | Aviation: Defense | 5 | 3 | 5 | 4 | 2 | **14** |
| 17 | Agriculture: Veterinary | 2 | 4 | 3 | 2 | 5 | **14** |
| 19 | Defense: Command and Control | 4 | 3 | 4 | 4 | 2 | **13** |
| 20 | National Security: Counterterrorism and Counter-Narcotics | 3 | 3 | 2 | 3 | 1 | **9** |

### Reading the matrix

- **Top tier (17 to 19):** Medical devices and automotive stand out because the rigorous standards map directly onto embedded work and hiring demand is strong. The 17-point group is broader: payments, investing, farming, and food safety trade some embedded fit for easier access and a lighter process.
- **Process weight vs. score:** The highest-scoring industries are also the heaviest (medical devices, automotive, aviation). If you want a lighter load, Sustainable Farming and Insurance score well with process weight 2.
- **Entry openness drags down** all three defense and counterterrorism entries. Careers there typically require citizenship and clearance eligibility, and public project material is thin.
- **Scores are coarse.** A one-point gap is within my judgment error. Use the matrix to shortlist, then decide on interest and on which project you would actually enjoy building.

### Clusters (for picking one or combining)

| Cluster | Industries | Shared themes |
|---|---|---|
| Safety-critical embedded | Medical Equipment, Automotive, Aviation (all three), Fire and Rescue, HAZMAT | Hazard analysis, safety integrity levels, fail-safe state machines, traceability, verification evidence |
| Financial systems | Payments, Investing, Insurance | Ledger/audit integrity, AML, model governance, records retention, fraud controls |
| Public safety and resilience | Emergency Management, Fire and Rescue, HAZMAT, Public Health Emergencies | NIMS/ICS, availability under degraded conditions, alerting standards (CAP/EDXL), exercises |
| One Health and food | Sustainable Farming, Veterinary, Food Safety, Public Health | Traceability, residue/withdrawal tracking, cold chain, surveillance data |
| Security and defense | Defense C2, Aviation Defense, Counterterrorism, Cybercrime | RMF/NIST controls, chain of custody, access control, audit, clearance limits |

### Artifacts that transfer across almost every industry

If you are unsure which industry to pick, building these well is useful everywhere:

1. **Requirements-to-test traceability matrix** (two-way).
2. **Hazard or threat analysis** (FMEA/HARA for safety, STRIDE/TARA for security).
3. **Deterministic mode/state machine** with documented safe and degraded states.
4. **Tamper-evident audit log** (hash-chained records with timestamps).
5. **SBOM and third-party component inventory** (SOUP/OTS).
6. **Control-mapping document** (your controls mapped to a named standard).
7. **Verification evidence** (coverage reports, static analysis results, test reports).
8. **Configuration management and change records.**

A reasonable strategy: build one modular "compliance-ready" core (state machine, logging, secure boot or signing, traceability tooling), then layer an industry overlay on top once you choose.

---

## Part 2: Industry Profiles

### 1. Healthcare: General

**Regulations**
- HIPAA (Privacy, Security, Breach Notification rules), HITECH
- FDA 21 CFR Part 11 (electronic records/signatures), Part 820 (QMSR, aligned with ISO 13485), Part 803 (adverse event reporting)
- 21st Century Cures Act and ONC information-blocking rules
- EU: GDPR, MDR 2017/745, IVDR, EU AI Act
- Other: PIPEDA (Canada), Japan PMDA, China NMPA

**Standards**
- ISO 13485 (QMS), ISO 14971 (risk), IEC 62304 (software lifecycle, Classes A/B/C), IEC 62366 (usability), IEC 60601 family (incl. 60601-1-2 EMC)
- ISO 27001, NIST 800-53, NIST CSF, HITRUST CSF, IEC 81001-5-1
- FDA premarket cybersecurity guidance (SBOM, threat modeling)

**Frameworks and platforms**
- HL7 v2, HL7 FHIR, CDA/C-CDA, DICOM, IHE profiles
- SNOMED CT, LOINC, ICD-10, RxNorm, CPT; SMART on FHIR, USCDI
- IEEE 11073, Continua/PCHAlliance

**Dev stacks**
- EHR/clinical: Java, C#/.NET, Python, TypeScript/React; HAPI FHIR, Mirth Connect, Rhapsody, Epic/Cerner APIs
- Cloud with BAAs: AWS, Azure, GCP, managed FHIR stores
- Embedded: C/C++ (MISRA), FreeRTOS/Zephyr/SafeRTOS/INTEGRITY, BLE
- Imaging/AI: Python, PyTorch, ITK/VTK, pydicom, MONAI

**Process and compliance**
- FDA device classes I/II/III; 510(k), De Novo, PMA pathways
- Design controls, design history file, requirements-to-test traceability, V&V
- IEC 62304 software safety class drives rigor; SOUP management; SBOMs
- Audit logging, encryption, access control, PHI de-identification
- Post-market surveillance, CAPA, change control

**Student-project feasibility** (added for this compilation)
- Health IT side is strong: FHIR sandboxes and HIPAA text are free. A FHIR-based app with audit logging, access control, and a HIPAA Security Rule control mapping is achievable using synthetic data. For the device side, see Medical Equipment and Tech.

**Key insight:** Healthcare splits into two worlds. Health IT (EHRs, apps) is governed mainly by HIPAA, FHIR, and security frameworks. Medical devices (SaMD and embedded) are governed by FDA/MDR, ISO 13485, 14971, and IEC 62304. Most of the heavy process lives in the second.

---

### 2. Healthcare: Public Health

**Regulations**
- HIPAA public health exception (45 CFR 164.512(b))
- State/local reportable disease laws; CDC NNDSS aggregation
- CLIA, 42 CFR Part 2, Public Health Service Act, CARES Act (COVID lab reporting), Cures Act info-blocking
- FERPA (school health data), Common Rule (45 CFR 46) and the research vs. surveillance distinction
- International: WHO International Health Regulations (2005), GDPR

**Standards**
- CDC Data Modernization Initiative, Public Health Data Strategy
- NIST 800-53/FedRAMP, FISMA for federal systems
- HL7 v2.5.1 ELR/ORU (lab reporting), HL7 v2 ADT (syndromic surveillance), CDC PHIN messaging guides
- WCAG 2.1 / Section 508 for public portals

**Frameworks and platforms**
- FHIR and FHIR Bulk Data; eCR (electronic case reporting) via eICR/RR, AIMS platform, eCR Now
- CDA/C-CDA, Direct Secure Messaging, TEFCA
- Immunization: HL7 VXU, IIS, CDC CVX/MVX codes
- SNOMED CT, LOINC, ICD-10, NDC, RxNorm; OMOP CDM, OHDSI, PCORnet
- DHIS2, OpenHIE, OpenSRP/OpenMRS, CommCare, ODK/KoboToolbox
- GIS: Esri ArcGIS, QGIS, PostGIS

**Dev stacks**
- Python, R (epitools, EpiEstim), SQL, Spark, dbt
- Cloud gov regions, Azure Health Data Services
- NBS (NEDSS Base System, Java/JBoss), SAS (still common in state agencies), Tableau/Power BI
- JavaScript/TypeScript, React, Flutter/React Native, offline-first sync (CouchDB/PouchDB)
- Modeling: SIR/SEIR, agent-based (NetLogo, Mesa)
- Embedded/IoT angle: wastewater sensors, environmental monitors, LoRaWAN, point-of-care diagnostics

**Process and compliance**
- De-identification (HIPAA Safe Harbor vs. Expert Determination), small-cell suppression
- Data use agreements and MOUs between agencies
- Role-based access, audit logs, minimum necessary principle
- Data quality and timeliness metrics; NIMS/ICS; CDC PHEP program
- Grant-driven compliance (CDC ELC funding)

**Student-project feasibility** (added for this compilation)
- Strong: free HL7/ELR/eCR specs plus synthetic data. A lab-report ingestion pipeline with de-identification, small-cell suppression, and audit logs is realistic.

**Key insight:** Public health IT is defined by legacy plus fragmentation. Thousands of jurisdictions use HL7 v2 and SAS alongside modern FHIR and cloud pipelines, so the real work is integration, data quality, and privacy-preserving aggregation.

---

### 3. Healthcare: Medical Equipment and Tech

**Regulations**
- FDA: 21 CFR Part 820 (QMSR), Part 11, Part 801 (labeling), Part 806 (recalls), Part 807 (510(k)), UDI rule (Part 830)
- FDA guidance: premarket software content, cybersecurity (SBOM, threat model), predetermined change control plans for AI
- Section 524B FD&C Act (cyber requirements for "cyber devices")
- EU: MDR 2017/745, IVDR, EU AI Act, NIS2
- Global: Health Canada MDSAP, PMDA, NMPA, UK MHRA (UKCA)

**Standards**
- ISO 13485, ISO 14971, ISO 15223, ISO 20417
- IEC 62304, IEC 82304-1, IEC 62366-1
- IEC 60601-1 family (-1-2 EMC, -1-8 alarms, -1-11 home use, particular standards such as 60601-2-24 infusion pumps)
- IEC 81001-5-1, AAMI TIR57/TIR97, UL 2900, ISO 27001, IEC 62443

**Frameworks and protocols**
- BLE, Wi-Fi, USB, IEEE 11073, Continua; HL7/FHIR, DICOM
- MQTT, TLS 1.2+, secure boot, signed OTA updates (MCUboot)
- IMDRF SaMD guidance

**Dev stacks**
- Firmware: C/C++ (MISRA C:2012, MISRA C++:2023, CERT C), some Ada/SPARK and Rust
- RTOS: FreeRTOS/SafeRTOS, Zephyr, ThreadX, INTEGRITY, QNX, VxWorks
- MCUs: ARM Cortex-M/R (STM32, Nordic nRF52/53, NXP i.MX RT), Linux SoCs for imaging/UI
- Toolchain: IAR, Keil, GCC, LDRA, Polyspace, Coverity, Cppcheck, VectorCAST, Unity/Ceedling
- UI: Qt, TouchGFX, LVGL
- Traceability: Jama, Polarion, Codebeamer, Doorstop (free), Jira plus plugins
- Modeling: Simulink/Stateflow, UML/SysML, FSMs for mode logic

**Process and compliance**
- Device class (I/II/III) and IEC 62304 class (A/B/C) set rigor
- Design controls: user needs, design inputs, outputs, V&V, design history file
- Risk file: hazard analysis, FMEA, fault trees, risk-control traceability
- SOUP/OTS inventory; cybersecurity (STRIDE, SBOM, vulnerability management, pen testing)
- Verification: unit/integration/system tests with coverage and static analysis evidence
- Post-market: complaints, CAPA, vigilance reporting

**Student-project feasibility**
- Very strong. FDA guidance, IMDRF docs, and open tools (Doorstop, Cppcheck, Ceedling, Zephyr) are free.
- Emulate a full 62304-style package on an ESP32 or Cortex-M device: software plan, requirements, architecture, risk file, SOUP list, traceability matrix, test reports, SBOM.
- Limit: no formal certification; a mock design history file is still a credible portfolio artifact.

**Key insight:** This is the heaviest-process slice of healthcare and maps directly onto embedded work. It is also the most documentation-intensive option in the first tier.

---

### 4. Aviation: Commercial Flights

**Regulations**
- FAA: 14 CFR Parts 25, 21, 121, 39; AC 20-115D recognizes DO-178C
- EASA: CS-25, Part 21, Part-145; AMC 20-115, AMC 20-152A (DO-254), AMC 20-42 (airborne networks/cyber)
- ICAO Annexes; Transport Canada, CAAC mirror FAA/EASA
- Cyber: FAA Part 25 special conditions, EASA Part-IS

**Standards**
- DO-178C / ED-12C with supplements DO-331 (model-based), DO-332 (OO), DO-333 (formal methods), DO-330 (tool qualification)
- DO-254 / ED-80 (complex hardware), DO-160G (environmental), DO-297 (IMA)
- ARP4754A (system development), ARP4761 (safety assessment: FHA, PSSA, SSA, FTA, FMEA)
- DO-326A / ED-202A, DO-356A (airworthiness security)
- ARINC 653 (partitioned RTOS API), ARINC 429 / 664 (AFDX) / 825, ARINC 661, ARINC 818; MIL-STD-1553
- AS9100, AS9102; MISRA C/C++, CERT C

**Dev stacks**
- Languages: C, Ada/SPARK, restricted C++, emerging Rust
- RTOS: VxWorks 653, INTEGRITY-178, PikeOS, LynxOS-178, DEOS
- Hardware: PowerPC, ARM Cortex-R, FPGAs (VHDL/Verilog)
- Model-based: SCADE Suite, Simulink/Embedded Coder
- Verification: VectorCAST, LDRA, Rapita, Polyspace, Astree, Frama-C, CompCert
- Traceability: DOORS Next, Polarion, Jama, Codebeamer

**Process and compliance**
- Design Assurance Levels (DAL A to E) by failure-condition severity; DAL A brings the most objectives
- Artifacts: PSAC, SDP, SVP, SCMP, SQAP, SAS, requirements (HLR/LLR), traceability, reviews
- Structural coverage: statement (C), decision (B), MC/DC (A)
- Independence between developers and verifiers at higher DALs; tool qualification (TQL)
- Configuration management and problem reporting; certification liaison (DERs/ODA, EASA CRIs)

**Student-project feasibility**
- Moderate to strong. DO-178C is paywalled (RTCA) but widely summarized; FAA handbooks are free.
- Emulate the process on a small flight-control or sensor-fusion project: MC/DC coverage, bidirectional traceability, PSAC, safety assessment. Free tooling: Ada/SPARK with GNAT Community, Frama-C, Cppcheck, gcov.
- Limit: no DER review or tool qualification.

**Key insight:** Aviation has the most rigorous and mature software assurance culture of any industry here. Rigor scales with DAL, so a DAL-C-style project is a practical student target.

---

### 5. Aviation: Shipping (Air Cargo and Logistics)

Airworthiness rules (DO-178C, ARP4754A, Part 25) are the same as commercial aviation. This profile covers what differs: cargo operations, dangerous goods, security, and logistics software.

**Regulations**
- FAA: 14 CFR Part 121 (freighters), Part 135 (on-demand cargo), Part 107 (small drones), Part 108 (BVLOS, proposed/emerging)
- Dangerous goods: 49 CFR Parts 171-180, ICAO Annex 18 and Technical Instructions, IATA DGR (lithium batteries a major focus)
- Security: TSA 49 CFR Part 1548 (indirect air carriers), Known Shipper, Certified Cargo Screening Program, ACAS (CBP)
- Customs: WCO SAFE Framework, C-TPAT, ACE, EU ICS2
- Weight and balance: 14 CFR 121, AC 120-27
- Europe: EASA Part-CAT/Part-SPO, EU 2015/1998 (aviation security), U-space

**Standards**
- IATA Cargo-XML, Cargo-IMP, ONE Record (linked-data shipment standard); IATA CEIV (Pharma, Live Animals, Lithium Batteries)
- ISO 28000, ISO 9001, AS9100; ULD standards (NAS 3610, TSO-C90d)
- GS1 (barcodes, EPC/RFID), EDIFACT (FWB, FHL, FFM)
- Drones: ASTM F3411 (Remote ID), F3548 (UTM), DO-365 (detect-and-avoid), DO-362 (C2 link)

**Frameworks and platforms**
- Cargo management: CHAMP Cargospot, IBS iCargo, Riege, WiseTech CargoWise
- Load planning and weight-and-balance engines; track-and-trace with RFID/BLE/IoT and cold-chain loggers
- Integration: REST/JSON, ONE Record APIs, EDI gateways, AS2/SFTP
- Flight ops: EFBs, dispatch/flight planning, ACARS, ADS-B

**Dev stacks**
- Logistics: Java, .NET, Python, SQL, Kafka, cloud, SAP integration
- Edge/IoT: C/C++, Rust, ESP32/nRF, LoRaWAN, BLE, MQTT
- Drone delivery: PX4/ArduPilot, MAVLink, ROS 2, Jetson/Pi companion computers
- Optimization: Python, OR-Tools, Gurobi

**Process and compliance**
- Dangerous-goods training and shipper declarations; lithium-battery packing rules
- Chain of custody and tamper-evident audit logs; e-AWB legal acceptance by country
- Safety Management System per ICAO Annex 19 / 14 CFR Part 5
- Drones: SORA (EASA) risk assessment, ConOps, Part 135 pathway
- Data integrity for customs filings; security-screening record retention

**Student-project feasibility**
- Two tracks. Logistics/traceability (ONE Record-style API, dangerous-goods validation, weight-and-balance calculator with audit logging) is very achievable with public specs.
- Drone delivery (PX4, SORA-style risk assessment, Remote ID) keeps the embedded and safety focus with free simulators (Gazebo, SITL).
- Limit: no air operator certificate.

**Key insight:** Cargo aviation splits into heavy-assurance airborne systems (same as passenger) and a lighter but regulation-dense ground logistics layer around dangerous goods, security, and customs data.

---

### 6. Aviation: Defense

**Regulations and legal**
- ITAR (22 CFR 120-130) and EAR; DFARS 252.204-7012 (covered defense information), 252.204-7021 (CMMC)
- CMMC 2.0 (built on NIST 800-171/172); FAR/DFARS, DCMA oversight
- DoDD 5000.01/5000.02, DoDI 5000.87 (software acquisition pathway)
- Airworthiness authorities: NAVAIR, AFLCMC, Army DEVCOM; MIL-HDBK-516C
- UK: Def Stan 00-970, 00-055; Europe: EMAR

**Standards**
- MIL-STD-882E (system safety), DO-178C / DO-254, ARP4754A/4761
- MIL-STD-810H, MIL-STD-461G, MIL-STD-704
- MIL-STD-1553B / 1760, ARINC 429/664, STANAG 3910, Link 16 / MIL-STD-6016
- FACE, SOSA, MOSA
- NIST 800-53 / 800-171 / RMF, DISA STIGs, Common Criteria, FIPS 140-3, DO-326A, NIST 800-160
- DO-297 (IMA); JSF C++ AV Rules, MISRA

**Dev stacks**
- C, Ada/SPARK, restricted C++, some Rust; VHDL/Verilog
- RTOS: VxWorks 653, INTEGRITY-178 tuMP, LynxOS-178, PikeOS, DEOS
- Middleware: DDS (RTI Connext DDS Cert), ARINC 653, FACE-conformant units
- Model-based: SCADE, Simulink, Cameo (SysML)
- DevSecOps: Platform One, Iron Bank containers, Kubernetes
- Verification: VectorCAST, LDRA, Rapita, Polyspace, Astree, Frama-C, Cantata

**Process and compliance**
- RMF: categorize, select, implement, assess, authorize, monitor; ATO
- System safety: PHA, SHA, SSHA; safety assessment reports; risk acceptance at the appropriate authority level
- Software: DAL allocation or MIL-STD-882 Software Safety Criticality Index
- Clearances, facility clearances, TEMPEST
- Supply chain: counterfeit parts (DFARS 252.246-7007/7008), SBOM, NIST 800-161
- Data rights and technical data package control; DT/OT and flight-test safety plans

**Student-project feasibility**
- Moderate. MIL-STD-882E, NIST publications, DISA STIGs, FACE/SOSA standards, and MIL-HDBK-516 overviews are public.
- Good project: small UAS flight controller or mission computer with a MIL-STD-882 hazard analysis, NIST 800-171 control mapping, STIG hardening, SBOM, and DO-178C-style traceability.
- Limits: no classified work; no ITAR-controlled data in public repos; unclassified public material only.

**Key insight:** Defense aviation layers security compliance (RMF, CMMC, export control) on top of safety assurance. Showing both is a differentiator. Careers often require citizenship and clearance eligibility.

---

### 7. Fintech: Insurance (Insurtech)

**Regulations**
- US state-based regulation via state DOIs, coordinated by NAIC
- NAIC Insurance Data Security Model Law (#668); NYDFS 23 NYCRR 500
- NAIC Model Bulletin on AI; Colorado SB21-169 (unfair discrimination in AI/big data)
- GLBA (Safeguards, privacy), CCPA/CPRA, FCRA (credit-based insurance scores), HIPAA (health/disability lines), SOX
- Solvency: RBC, ORSA, Solvency II; accounting: IFRS 17, US GAAP LDTI
- EU: GDPR, DORA, IDD, EU AI Act (life/health pricing high-risk)
- Anti-fraud and AML: state fraud reporting, OFAC, BSA/AML for some life and annuity products

**Standards**
- ISO 27001, SOC 2 Type II, NIST CSF, NIST 800-53, PCI DSS
- ACORD data standards (Next Gen Digital Standards)
- ISO 20022, ISO 22301, ISO/IEC 42001 (AI management)
- SERFF rate and form filings; SR 11-7-style model validation; actuarial standards of practice (ASOPs)

**Frameworks and platforms**
- Core systems: Guidewire (PolicyCenter/ClaimCenter/BillingCenter), Duck Creek, Majesco, Sapiens, Insurity
- Integration: REST/JSON, ACORD messaging, Kafka
- Claims tech: computer vision for damage, NLP on claim notes, telematics (usage-based insurance)
- Rules engines (Drools), actuarial models, feature stores
- Data sources: ISO ClaimSearch, LexisNexis, CLUE, MVR, Verisk, geospatial risk
- Embedded insurance via partner APIs

**Dev stacks**
- Backend: Java/Kotlin (Guidewire GOSU), C#/.NET, Python, Go; Spring Boot
- Data/ML: scikit-learn, XGBoost/GLMs, Spark, Databricks/Snowflake, MLflow, SHAP/LIME
- Frontend: React/Angular, WCAG-accessible portals
- Cloud/DevOps: AWS/Azure, Terraform, Kubernetes, SIEM
- Telematics/IoT: OBD-II dongles and BLE sensors (C/C++, ESP32, CAN), smartphone SDKs, home-IoT leak/fire sensors

**Process and compliance**
- Model governance: documentation, bias/disparate-impact testing, human oversight, adverse action notices
- Rate and form filings; audit trails of rating-factor changes
- Data governance: consent, retention, PII/PHI minimization, vendor risk
- Fraud detection (explainable rules plus ML), SIU workflows
- Market-conduct exams; change management and segregation of duties
- Incident response and 72-hour regulator notification (NYDFS, NAIC)

**Student-project feasibility**
- Strong. NAIC models, NYDFS 500, NIST CSF, GLBA text, and ACORD samples are public.
- Good project: usage-based insurance telematics pipeline (embedded sensor, API, risk scoring) with bias testing, explainability report, SOC 2-style control mapping, NYDFS 500 alignment.
- Alternative: rules-based claims or underwriting engine with audit logging and model documentation.
- Limits: synthetic data only, no regulator filing.

**Key insight:** Insurance GRC is about data governance, algorithmic fairness, and cyber resilience rather than physical safety. The documentation burden is lighter than devices or aviation, but AI governance is where regulation is moving fastest.

---

### 8. Fintech: Digital Payments and Transfers

**Regulations**
- Money transmission: state Money Transmitter Licenses, FinCEN MSB registration (31 CFR 1010/1022)
- BSA/AML: KYC/CIP, CDD rule, SARs/CTRs, FinCEN Travel Rule, OFAC
- Consumer: Reg E (EFTA), Reg Z, UDAAP, CFPB 1033 (open banking), CFPB supervision of large payment apps
- Privacy/security: GLBA, CCPA/CPRA, FFIEC guidance, NYDFS 500
- Nacha Operating Rules (ACH); card network rules
- Crypto-adjacent: state BitLicense, MiCA, FATF VASP guidance
- EU/UK: PSD2/PSD3 (SCA, open banking), PSR, GDPR, DORA, e-money licensing, FCA
- Global: MAS, RBI (UPI), PBoC, FATF

**Standards**
- PCI DSS v4.0, PCI PIN, PCI P2PE, PCI 3DS, PCI Secure Software Standard
- EMV (chip, contactless, tokenization), 3-D Secure 2, ISO 8583, ISO 20022
- ISO 27001, SOC 1/SOC 2, NIST CSF, NIST 800-63, FIDO2/WebAuthn
- OAuth 2.0 / OIDC, FAPI, Open Banking UK, FDX
- ISO 9564 (PIN), FIPS 140-3 (HSMs), TR-31/TR-34

**Frameworks and rails**
- ACH, Fedwire, FedNow, RTP, card networks, SEPA/SEPA Instant, UPI, Pix, SWIFT gpi
- Stripe, Adyen, Plaid, Marqeta, Modern Treasury, Dwolla, Wise
- Patterns: double-entry ledgers, idempotency keys, event sourcing, sagas, reconciliation
- Fraud/risk: rules plus ML, device fingerprinting, chargeback management
- KYC vendors (Persona, Onfido, Jumio); OFAC SDN list

**Dev stacks**
- Java/Kotlin, Go, C#/.NET, Python, Rust; Postgres, Kafka, Redis
- HSMs (Thales, Utimaco, AWS CloudHSM), tokenization, envelope encryption, mTLS
- React, Swift/Kotlin, Apple Pay/Google Pay SDKs, NFC HCE
- Embedded: POS terminals and card readers (C/C++, secure elements, EMV kernels), Android-based terminals, secure boot, tamper detection

**Process and compliance**
- AML program: written policy, BSA officer, independent testing, training
- Transaction monitoring and case management with audit trails
- Ledger integrity, segregation of duties, reconciliation and settlement controls
- PCI scope reduction (tokenization, hosted fields); quarterly scans; ROC/SAQ
- Sponsor-bank and vendor oversight; incident response; Reg E dispute timelines

**Student-project feasibility**
- Very strong. PCI DSS, NIST 800-63, FAPI, Nacha summaries, and sandbox APIs (Stripe test mode, Plaid sandbox) are free.
- Good project: double-entry ledger with idempotent transfers, tamper-evident audit logs, PCI-style scope design (tokenize, never store PANs), KYC/sanctions stub, control mapping to PCI DSS and SOC 2.
- Embedded variant: secure contactless payment terminal prototype on ESP32/STM32 with secure boot and key storage (EMV-inspired, not certified).
- Limits: no real funds, no MTL, no EMVCo certification; synthetic data and test modes only.

**Key insight:** Payments GRC is dominated by money-movement controls: AML, ledger integrity, fraud, and cardholder-data security. It is prescriptive and audit-driven, with a clear path to demonstrate compliance through technical controls you can implement.

---

### 9. Fintech: Investing

**Regulations**
- SEC: Exchange Act of 1934, Investment Advisers Act of 1940, Investment Company Act of 1940
- Reg BI, fiduciary duty for RIAs, Reg SCI, Reg S-P, Reg S-ID, Reg ATS, Reg NMS
- Rule 15c3-5 (market access risk controls), Rule 17a-4 (records retention, WORM/audit trail)
- FINRA: Rules 2111 (suitability), 3110 (supervision), 4511 (books and records), CAT reporting, communications rules
- AML: BSA/CIP/CDD, SARs, OFAC; tax: IRS 1099-B/cost basis, FATCA/CRS
- Digital assets: evolving SEC/CFTC jurisdiction, custody rules, state licensing
- Global: MiFID II/MiFIR, ESMA, FCA, DORA, MAS, ASIC

**Standards**
- FIX protocol (and FIXML), ISO 20022, ISO 15022 / SWIFT
- ISO 27001, SOC 1/SOC 2, NIST CSF, NIST 800-53
- FIPS 140-3, OAuth 2.0 / FAPI, FIDO2
- Model risk: SR 11-7-style validation; MiFID II clock sync (RTS 25), PTP/NTP traceability
- Market data: ITCH/OUCH, SIP feeds

**Frameworks and platforms**
- Brokerage infrastructure: DriveWealth, Apex Clearing, Alpaca, Interactive Brokers API
- OMS/EMS, smart order routers, FIX engines (QuickFIX), matching engines
- Robo-advice: rebalancing, tax-loss harvesting, risk profiling
- Market data: Bloomberg, LSEG, Polygon, IEX
- Quant: Backtrader, Zipline, QuantLib, pandas, vectorbt
- Compliance tech: trade surveillance, communications archiving, pre-trade risk checks

**Dev stacks**
- Low-latency: modern C++ (lock-free, kernel bypass), Rust, Java (LMAX Disruptor), FPGA
- General backend: Java/Kotlin, Go, Python, Kafka, Postgres, TimescaleDB/kdb+
- Quant/ML: Python, NumPy/pandas, PyTorch, R
- Systems overlap: deterministic order-lifecycle state machines, memory-layout tuning, lock-free queues, real-time performance

**Process and compliance**
- Pre-trade risk controls (fat-finger, position/credit limits, kill switches)
- Best-execution analysis; audit trails and immutable order history; CAT clock accuracy
- Suitability/Reg BI logic; disclosure and conflict management
- Books and records retention (WORM, multi-year); e-communications archiving
- Change management for trading algorithms; business continuity and Reg SCI incident reporting

**Student-project feasibility**
- Strong. SEC/FINRA rules, FIX specs, and broker sandboxes (Alpaca paper trading, IBKR paper accounts) are free.
- Good project: paper-trading OMS with a deterministic order state machine, Rule 15c3-5-style pre-trade risk checks, immutable audit log, FIX-style messaging, control matrix.
- Systems variant: low-latency matching engine in C++ with replay-based testing and latency measurement.
- Limits: simulated only; no customer funds, no real investment advice.

**Key insight:** Investing GRC centers on market integrity and customer protection: best execution, suitability, risk limits, and record retention. It rewards deterministic, auditable, performance-sensitive systems work.

---

### 10. National Security: Emergency Management

**Regulations and policy**
- Stafford Act, Post-Katrina Emergency Management Reform Act, Homeland Security Act
- PPD-8, PPD-21 and NSM-22 (critical infrastructure)
- FISMA, CIRCIA, Cybersecurity Information Sharing Act
- NIMS / ICS, National Response Framework, National Disaster Recovery Framework
- FCC: Part 11 (EAS), WEA, NG911; IPAWS
- Privacy Act, Section 508; state emergency operations plans; EMAC mutual aid
- International: Sendai Framework, EU Civil Protection Mechanism, NIS2

**Standards**
- NFPA 1600, NFPA 1221, NFPA 72
- ISO 22301, ISO 22320, ISO 27001
- NIST 800-53, 800-34 (contingency planning), 800-61, CSF 2.0, 800-82 (ICS)
- CAP (Common Alerting Protocol), EDXL family, NIEM
- APCO P25, FirstNet, TETRA, NENA i3 (NG911)
- IEC 62443; ISO 19115 (geo metadata)

**Frameworks and platforms**
- WebEOC, Everbridge, Hexagon CAD, RapidSOS, ArcGIS (EOC dashboards)
- Alerting: IPAWS-OPEN, WEA, EAS, cell broadcast, SMS gateways
- GIS/situational awareness: Esri, QGIS, PostGIS, OpenStreetMap, NASA FIRMS, FEMA flood maps
- Comms resilience: mesh (Meshtastic, goTenna), LoRa, satellite, HF/amateur radio (ARES)
- Modeling: HAZUS, evacuation models, HEC-RAS

**Dev stacks**
- Python, Java, Go, PostgreSQL/PostGIS, message queues, offline-first sync
- React with Leaflet/Mapbox/OpenLayers; PWAs for degraded networks
- Embedded/IoT: C/C++, Rust, ESP32/nRF, LoRa/Meshtastic, flood/air-quality/seismic sensors, solar/battery design
- Drones and robotics: PX4/ArduPilot, MAVLink, ROS 2
- Ops: edge Kubernetes, air-gapped deployments, STIG hardening
- Resilience patterns: graceful degradation, store-and-forward, redundancy, priority queuing

**Process and compliance**
- NIMS/ICS structures reflected in tooling roles
- COOP and continuity planning, business impact analysis
- Exercises (HSEEP), after-action reports
- Alert authority and message accuracy, false-alarm prevention, multilingual and accessibility (ADA) requirements
- Data-sharing governance (MOUs, need-to-know); RTO/RPO targets and failover testing
- Security authorization (RMF/ATO) for federal systems

**Student-project feasibility**
- Strong. NIST, NFPA summaries, FEMA/CISA guidance, CAP/EDXL specs, NIMS materials, and HSEEP docs are free.
- Good project: off-grid mesh sensor network (ESP32/LoRa) for flood or fire monitoring that publishes CAP-formatted alerts, with a NIST 800-34-style contingency plan, RTO/RPO targets, failure-mode analysis, and an HSEEP-style tabletop exercise report.
- Software variant: offline-first incident tracker with ICS role mapping, audit logs, and NIEM/EDXL export.
- Limits: no IPAWS access (requires authorization); keep alerts in a sandbox.

**Key insight:** Emergency management GRC is about availability, resilience, and interoperability under failure. Requirements center on systems working when networks, power, and staff are degraded.

---

### 11. National Security: Counterterrorism and Counter-Narcotics

**Regulations and legal authorities**
- Intelligence/surveillance: FISA (incl. Section 702), EO 12333, USA FREEDOM Act, ECPA, Stored Communications Act, 4th Amendment case law
- Privacy oversight: Privacy Act of 1974, PCLOB, civil liberties officers, AG Guidelines, minimization procedures
- Financial: Bank Secrecy Act, USA PATRIOT Act (Sec. 311, 314, 326), FinCEN rules, OFAC sanctions (IEEPA), Kingpin Act
- Narcotics: Controlled Substances Act, DEA scheduling and registration, Maritime Drug Law Enforcement Act
- Export/border: ITAR/EAR, CBP authorities, C-TPAT, CFIUS
- Information sharing: IRTPA, ISE, 28 CFR Part 23
- International: UN Security Council sanctions, FATF, Budapest Convention, Five Eyes, GDPR/Law Enforcement Directive

**Standards**
- NIST 800-53 / RMF, NIST 800-171, ICD 503, ICD 705, CNSSI 1253, DoD 8500/8510
- NIEM, N-DEx, STIX/TAXII, MITRE ATT&CK, SAR functional standard (ISE-FS-200)
- ISO 27001, FIPS 140-3, Common Criteria, NSA CNSA 2.0
- Digital evidence: ISO/IEC 27037, NIST 800-86, SWGDE
- Biometrics: ANSI/NIST-ITL, ISO/IEC 19794, NIST FRVT benchmarks

**Frameworks and platforms**
- Analyst tooling: link analysis, entity resolution, graph databases, geospatial fusion
- Financial-crime tech: transaction monitoring, sanctions/PEP screening, blockchain analytics (Chainalysis, TRM, Elliptic)
- Border and maritime: AIS tracking, sensor fusion, cargo risk scoring
- OSINT pipelines (subject to legal limits), multilingual NLP, media forensics
- Sharing: cross-domain solutions, classification-aware tagging (ABAC, XACML), Zero Trust

**Dev stacks**
- Python, Java, Scala, Spark, Elasticsearch/OpenSearch, graph databases
- ML with auditability and bias testing (PyTorch, NLP, vision)
- Linux hardening (STIGs), SELinux, air-gapped networks, containers, HSMs
- Embedded/secure comms: C/C++, Rust, hardened firmware, secure boot, tamper-evident hardware, SDR (GNU Radio)
- Low-power sensor nodes with encrypted telemetry

**Process and compliance**
- Authority-to-collect controls: legal-basis tagging, query justification, minimization, retention limits
- Audit and oversight: immutable access logs, IG reviews, congressional reporting
- Clearance and need-to-know enforcement; compartmentalization
- Data provenance and quality: source reliability grading, error correction, redress
- AML/CTF programs: typology-based monitoring, SAR workflows, sanctions updates
- Evidence handling: chain of custody, hashing, forensic imaging
- Civil liberties and privacy impact assessments

**Student-project feasibility**
- Narrow and constrained. Real CT/CN systems are classified or law-enforcement sensitive.
- Public-analog projects: sanctions-screening and AML transaction-monitoring engine (OFAC SDN list is public), digital-evidence chain-of-custody tool with hashing and audit logs, privacy-preserving entity-resolution pipeline with PIA documentation.
- Free references: NIST, FinCEN guidance, FATF typologies, OFAC lists, STIX/TAXII specs, PCLOB reports.
- Limits: no real intelligence data, no surveillance tooling; stay in financial-crime and evidence-integrity territory.

**Key insight:** This field is governed by authorities and oversight (what you may collect, keep, and share) more than technical safety certification. It has the highest barriers to entry (citizenship, clearance) and the thinnest public student-project surface of any industry here.

---

### 12. Law Enforcement: Cybercrime

**Regulations and legal**
- CFAA, Wiretap Act, Stored Communications Act, Pen Register Act, ECPA
- CLOUD Act, Rule 41 (remote search warrants), 4th Amendment doctrine (Carpenter, Riley)
- Federal Rules of Evidence (authentication, hearsay, Rule 902(13)/(14)); Rules of Criminal Procedure
- Cybercrime statutes: identity theft, wire fraud, access device fraud, ransomware-related OFAC advisories
- Reporting: CIRCIA, state breach notification, SEC cyber disclosure
- Privacy: state privacy laws, GDPR/Law Enforcement Directive, 28 CFR Part 23, CJIS
- International: Budapest Convention, MLATs, Europol/Interpol, UN cybercrime convention

**Standards**
- FBI CJIS Security Policy (MFA, encryption, audit logging, personnel screening)
- NIST 800-86, 800-61, 800-53, CSF 2.0
- ISO/IEC 27037, 27041, 27042, 27043; ISO/IEC 17025 (lab accreditation)
- SWGDE, ASTM E2916, ANAB accreditation
- STIX/TAXII, MITRE ATT&CK, MISP, Traffic Light Protocol; RFC 3227
- FIPS 140-3; NIST 800-88 (media sanitization)

**Tools and frameworks**
- Disk/memory forensics: Autopsy/Sleuth Kit, EnCase, FTK, Magnet AXIOM, Volatility, X-Ways
- Mobile: Cellebrite, GrayKey, Magnet, ALEAPP/iLEAPP
- Network: Wireshark, Zeek, Suricata, NetFlow
- Logs/SIEM: Elastic, Splunk, Velociraptor, GRR; timelines via Plaso
- Threat intel: MISP, OpenCTI, passive DNS, certificate transparency
- Blockchain analysis: Chainalysis, TRM, Elliptic; evidence tracking and LIMS

**Dev stacks**
- Forensics tooling: Python, C/C++, Rust, Go; file-system internals (NTFS, APFS, ext4)
- Pipelines: Elasticsearch, Postgres, Kafka, Spark
- ML: anomaly detection, malware clustering, NLP on chats (with audit and explainability)
- Infrastructure: isolated lab networks, write blockers, hardened Linux, HSM-backed signing, hash-chained logs
- Embedded overlap: firmware extraction (JTAG/UART/SPI flash), bootloader analysis, IoT forensics, reverse engineering

**Process and compliance**
- Legal process first: warrant or consent scoping, documented authority before acquisition
- Chain of custody: hashing (SHA-256), write-blocking, tamper-evident seals, transfer logs
- Reproducibility: documented methods, tool validation, peer review, error-rate awareness (Daubert/Frye)
- Lab quality: ISO 17025 accreditation, proficiency testing, written SOPs
- Personnel access (CJIS background checks), victim and sensitive-data handling
- Incident coordination with CISA/FBI (IC3), ISACs, private sector

**Student-project feasibility**
- Strong and portfolio-friendly. NIST guidance, SWGDE, RFC 3227, the CJIS policy, ATT&CK, and sample images (Digital Corpora, NIST CFReDS) are free.
- Good project: forensic artifact parser or hash-chained evidence logger with chain-of-custody records, tool validation against CFReDS datasets, and a methodology aligned to ISO 27037 and NIST 800-86.
- Embedded flavor: firmware acquisition and analysis workflow for an ESP32 or similar IoT device.
- Limits: no real case data; never handle CSAM, even for testing; no offensive tooling.

**Key insight:** Cybercrime investigation GRC is about evidence admissibility: legal authority, integrity, reproducibility, and documentation. Technically it rewards low-level skills, and the compliance artifacts (chain of custody, validation records, SOPs) are concrete things you can build and demonstrate.

---

### 13. Emergency Services: Fire and Rescue

**Regulations and legal**
- OSHA: 29 CFR 1910.156 (fire brigades), 1910.134 (respirators), 1910.120 (HAZWOPER), 1910.146 (confined spaces)
- Fire codes: International Fire Code and NFPA 1, adopted by states/localities (AHJ)
- Building/life safety: NFPA 101, International Building Code
- EMS overlap: state EMS licensing, HIPAA (patient care reports), NEMSIS
- Emergency comms: FCC public safety spectrum, NG911 (NENA i3), FirstNet
- Wildland: NWCG standards, federal wildland fire policy
- HazMat: EPCRA (Tier II), 49 CFR, CERCLA, DOT ERG
- Federal funding: NIMS adoption for grants, NFIRS reporting
- International: EN standards for PPE/equipment

**Standards**
- NFPA 1710 / 1720 (staffing and response times), NFPA 1500, NFPA 1001/1002/1006
- NFPA 1971 / 1981 / 1852 (turnout gear, SCBA), NFPA 1901 (apparatus), NFPA 1221, NFPA 1061
- NFPA 72 (fire alarm), NFPA 13 (sprinklers), NFPA 25, NFPA 1600
- Data exchange: NFIRS, NEMSIS, CAP/EDXL, NENA standards, APCO ANS
- NFPA 2400 (small UAS for public safety)
- Product: UL 864 (control units), UL 217 (smoke alarms), UL 2034 (CO alarms), EN 54, IEC 61508 concepts

**Frameworks and platforms**
- CAD/RMS: Tyler, Hexagon, Motorola, ESO, ImageTrend, Emergency Reporting
- Station alerting, AVL, MDTs in apparatus
- GIS and pre-incident plans: Esri, hydrant data, building floor plans
- Wildfire: NASA FIRMS, WFDSS, FARSITE, BehavePlus, PulsePoint
- Sensors and IoT: thermal imaging, gas detectors, firefighter location tracking, vital-sign wearables, drone thermal payloads
- Comms: P25, FirstNet LTE, mesh/LoRa, satellite backup

**Dev stacks**
- Enterprise: Java/.NET, PostgreSQL/PostGIS, REST APIs, NG911 integration
- Mobile/rugged: Android, offline-first sync, voice/hands-free interfaces
- Embedded and safety-critical: fire alarm panels and detectors (C/C++ on low-power MCUs, UL 864/217 firmware requirements, watchdogs, supervised circuits, fail-safe design); SCBA and gas monitor electronics (intrinsic safety, UL 913, ATEX/IECEx); firefighter tracking (BLE/UWB/LoRa, IMU dead reckoning); apparatus control over CAN/J1939
- Drones/robotics: PX4/ArduPilot, ROS 2, firefighting UGVs

**Process and compliance**
- Response-time measurement against NFPA 1710/1720 benchmarks
- NFIRS/NEMSIS submissions with QA/QC
- Training and certification records (Pro Board/IFSAC)
- Equipment inspection logs (SCBA flow tests, hose/ladder testing, apparatus service)
- Health and safety programs (exposure tracking, post-incident analysis)
- Safety-critical product development: UL listing process, FMEA, EMC/environmental testing, false-alarm rate targets
- CAD reliability: high availability, failover, audit trails of dispatch decisions

**Student-project feasibility**
- Strong and hands-on. NFPA codes are viewable free (read-only); NIST, USFA, NFIRS/NEMSIS specs, NWCG, and UL overviews are accessible.
- Good project: networked smoke/CO/temperature detector prototype (ESP32 or nRF) with supervised-loop behavior, watchdog and fail-safe states, FMEA, false-alarm analysis, and a UL 217/864-style requirements and test plan. Alarm/trouble/supervisory modes map directly onto a deterministic state machine.
- Software variant: CAD-style dispatch simulator measuring response times against NFPA 1710 benchmarks, with audit logs and NFIRS-style export.
- Limits: no UL listing; do not present it as life-safety certified.

**Key insight:** Fire and rescue GRC blends life-safety product standards (detectors, panels, SCBA) with operational performance standards (response times, training, reporting). The product side fits embedded safety design (fail-safe behavior, supervision, deterministic state machines) very well.

---

### 14. Emergency Services: HAZMAT

**Regulations and legal**
- OSHA: HAZWOPER (1910.120), 1910.134, Hazard Communication (1910.1200, GHS), 1910.146, Process Safety Management (1910.119)
- EPA: CERCLA/Superfund, EPCRA (Tier II, TRI, LEPC/SERC), RCRA, Clean Air Act 112(r) RMP, Clean Water Act spill rules (SPCC)
- DOT/PHMSA: 49 CFR 100-185 (HMR), placarding, shipping papers, ERG, CHEMTREC
- DHS: CFATS (authority lapsed in 2023; status in flux), TSA rail/pipeline security directives
- Transport: AAR, IMDG Code, IATA DGR / ICAO TI, ADR
- NRC/DOE for radiological materials; CDC/DOT for biological agents
- National Contingency Plan, NIMS/ICS, state release reporting (National Response Center thresholds)
- International: UN GHS, Seveso III, REACH/CLP

**Standards**
- NFPA 470 (HazMat/WMD response personnel), NFPA 1072, NFPA 1991 / 1992 / 1994 (chemical protective ensembles), NFPA 1851, NFPA 704, NFPA 30/45/49/400
- ISO 14001, ISO 45001, ISO 22301
- Detection and instruments: IEC 60079 (explosive atmospheres), ATEX/IECEx, UL 913 / UL 61010, IEC 60079-29 (gas detectors), IEC 61508 / 61511 (process safety SIL)
- Data exchange: SDS format (GHS 16-section), EDXL-HAVE/DE, CAMEO formats, CAP, NIEM
- Sampling/lab: EPA methods, ASTM, ISO/IEC 17025
- Process safety: ANSI/ISA-84, API RP 750/754, CCPS guidelines, HAZOP/LOPA

**Frameworks and platforms**
- CAMEO Suite (CAMEO Chemicals, ALOHA, MARPLOT), WISER, ERG apps, Tier2 Submit, EPA RMP*eSubmit
- Dispersion modeling: ALOHA, HPAC, AERMOD
- Sensors: multi-gas monitors (PID, LEL, electrochemical), radiation detectors, Raman/FTIR identifiers, drone-mounted sensors
- Command tools: ICS forms, WebEOC, GIS zone mapping, weather feeds
- Facility side: SCADA/DCS, safety instrumented systems, permit-to-work, management of change

**Dev stacks**
- Python, Java, PostgreSQL/PostGIS, GIS APIs, weather integration, REST/CAP alerting
- Embedded safety: multi-gas detectors (C/C++ on low-power MCUs, sensor calibration and drift compensation, alarm latching, fail-safe on sensor fault); intrinsic-safety constraints on power, components, connectors; industrial protocols (Modbus, HART, 4-20 mA, OPC UA, PROFIBUS/PROFINET); safety PLC logic (IEC 61131-3, SIL-rated controllers)
- Robotics/drones: ROS 2, PX4, UGVs with sensor payloads
- Modeling: Gaussian plume models in Python/NumPy, geospatial visualization, Monte Carlo uncertainty
- Edge: LoRa/mesh fenceline monitoring, battery/solar design

**Process and compliance**
- Hazard identification: SDS review, ERG lookup, placards, isolation distances
- Risk management plans and emergency response plans; LEPC coordination
- Exposure limits and alarm setpoints: OSHA PEL, NIOSH REL, ACGIH TLV, IDLH, AEGL/ERPG
- Calibration and maintenance with NIST-traceable gas standards
- Decontamination and PPE selection (Level A to D)
- Incident documentation and after-action review
- Functional safety lifecycle: hazard analysis, SIL allocation, design, verification, proof testing
- Environmental reporting: reportable quantities and notification timing

**Student-project feasibility**
- Strong with caveats. EPA, NOAA, PHMSA, OSHA, NIH WISER, ERG, and CAMEO are free; NFPA standards are viewable read-only.
- Good project: multi-gas monitoring node (ESP32 or STM32 with commodity sensors) with calibration logging, drift handling, alarm state machine, fail-safe on sensor fault, and a SIL-style hazard analysis and proof-test plan. Threshold logic tied to published exposure limits.
- Software variant: HazMat decision-support tool (ERG-style lookup, isolation distance logic, SDS parsing, auditable incident log, EDXL/CAP export).
- Limits: no intrinsic-safety certification; do not claim safety function; use benign test gases or simulated inputs; label as a research prototype.

**Key insight:** HAZMAT GRC ties chemical-specific regulation (OSHA, EPA, DOT) to detection and protective instrumentation standards. The strongest overlap for a developer is functional safety and sensor reliability: alarm state machines, calibration traceability, fail-safe design, and exposure-limit logic.

---

### 15. Healthcare: Public Health Emergencies (US and International)

Builds on the Public Health profile. New here: emergency authorities, countermeasure logistics, and the international layer.

**Regulations (US)**
- PHS Act Section 319 (HHS public health emergency declarations), National Emergencies Act, Stafford Act
- PAHPA (reauthorization has lapsed and been delayed; check status)
- FD&C Act Section 564 (EUA), PREP Act (liability protection for countermeasures), Project BioShield, BARDA
- Social Security Act Section 1135 waivers, EMTALA, CMS Emergency Preparedness Rule (42 CFR 482.15 and related)
- 42 CFR Parts 70/71 (quarantine), Part 73 (Select Agent Program)
- HIPAA 164.512(b) and (j); HHS disaster-disclosure bulletins
- State emergency powers and quarantine law; EMAC

**Regulations (international)**
- IHR (2005), amended in 2024 (adds a "pandemic emergency" tier); PHEIC declarations
- WHO Pandemic Agreement (adopted 2025) and its PABS annex (pathogen access and benefit-sharing, linked to the Nagoya Protocol); negotiation and ratification status is moving, so verify
- US announced WHO withdrawal, which affects participation in IHR mechanisms; verify current status
- GDPR, EU Health Security framework (ECDC, HERA), Africa CDC mandates, Biological Weapons Convention
- Global Health Security Agenda, JEE

**Standards**
- NIMS/ICS, HICS (hospital incident command), NFPA 1600, ISO 22320/22301
- ISO 35001 (biorisk management), CDC BMBL, WHO Laboratory Biosafety Manual, ISO 15189/17025
- Cold chain: WHO PQS device specifications, Good Distribution Practice, 21 CFR 210/211/600-series
- Devices: ISO 80601-2-12 (ventilators), 80601-2-61 (pulse oximeters), EUA conditions
- Pharmacovigilance: MedDRA, ICH E2B(R3), VAERS
- Humanitarian: Sphere Standards, Core Humanitarian Standard, IASC Health Cluster, WHO EMT classification
- Data: HL7 v2 ELR, FHIR, eICR/eCR, SNOMED CT, LOINC, ICD-10/11, OMOP

**Frameworks and platforms**
- Surveillance: WHO EIOS, ProMED, HealthMap, NWSS (wastewater), NSSP/BioSense, NHSN
- Outbreak response: Go.Data (WHO contact tracing), SORMAS, Epi Info, DHIS2 (incl. tracker), CommCare, ODK
- Genomics: GISAID, NCBI, Nextstrain, Pathoplexus, Nextflow/Snakemake
- Supply chain: Strategic National Stockpile processes, OpenLMIS, mSupply, CDC POD planning
- Interoperability: OpenHIE, OpenMRS, WHO SMART Guidelines, GDHCN
- Exposure notification: GAEN, DP-3T

**Dev stacks**
- Python, R, SQL, Spark, dbt, Docker; SEIR and agent-based models (Mesa, EpiEstim)
- Field apps: Android, Flutter/React Native, offline-first sync (CouchDB/PouchDB), SMS/USSD gateways (RapidPro, Africa's Talking)
- Backend: Java (DHIS2), Python/Django, PostgreSQL/PostGIS, FHIR servers (HAPI)
- Embedded: cold-chain loggers (BLE/LoRaWAN/NB-IoT), wastewater autosamplers, point-of-care readers, ventilator and oximeter firmware, open-source emergency ventilator designs
- Constraints: low bandwidth, intermittent power, multilingual UI, extreme heat in transit

**Process and compliance**
- Declaration and authority chain: who can declare, what powers unlock (waivers, EUAs, procurement)
- Countermeasure lifecycle: EUA, deployment, monitoring, transition to full approval
- Crisis standards of care and surge capacity plans
- Case investigation and contact tracing: consent, minimization, retention limits, sunset clauses
- Data-sharing agreements across jurisdictions; IRB and public-health-practice vs. research distinction
- Cold-chain integrity: continuous monitoring, excursion handling, traceable calibration
- After-action review and IHR reporting timelines (notify WHO within 24 hours of assessing a potentially notifiable event)

**Student-project feasibility**
- Strong. WHO PQS specs, CDC/ASPR toolkits, Go.Data and DHIS2 (open source), NWSS public data, DP-3T papers/code, and FDA EUA documents are free.
- Embedded: cold-chain monitor (ESP32 or nRF with temperature sensor) with excursion alarms, calibration log, tamper-evident data, a WHO PQS-style requirements list, and FMEA. Its alarm and trouble logic suits a state machine.
- Software: offline-first outbreak line-list and contact-tracing app with data minimization, audit logs, HIPAA/GDPR control mapping, FHIR/ELR export.
- Limits: synthetic data only; label device work as a research prototype, not a medical device or EUA candidate.

**Key insight:** The routine Public Health profile is about surveillance and reporting. This one is about emergency legal triggers, speed, and logistics: waivers and EUAs to act fast, cold-chain and stockpile integrity, and privacy controls that hold up under pressure. The international layer is partly political, so treat treaty status as a moving target.

---

### 16. Agriculture: Sustainable Farming

**Regulations and policy**
- USDA National Organic Program (7 CFR Part 205); Strengthening Organic Enforcement rule
- FSMA: Produce Safety Rule (21 CFR 112), Preventive Controls, Food Traceability Rule (FSMA 204; compliance date pushed to mid-2028, verify)
- EPA: FIFRA (pesticides, Worker Protection Standard), Clean Water Act (nutrient runoff, CAFOs), Clean Air Act, Endangered Species Act pesticide consultations
- Farm Bill programs: NRCS EQIP, CSP, CRP (conservation compliance)
- Climate programs and carbon-market frameworks (policy has shifted across administrations; verify)
- Water rights, state irrigation and nutrient management law
- Drones: FAA Part 107 and Part 137
- EU: Common Agricultural Policy (eco-schemes, conditionality), Farm to Fork, EU Organic Regulation 2018/848, EU Deforestation Regulation (EUDR), CSRD
- Global: Codex Alimentarius; GlobalG.A.P. as market access

**Standards and certifications**
- Organic: USDA Organic, EU Organic, IFOAM; Regenerative Organic Certified; Demeter
- Food safety: GFSI-benchmarked schemes (SQF, BRCGS, GlobalG.A.P.), HACCP
- Sustainability: SAI Platform FSA, Rainforest Alliance, Fair Trade, ISO 14001, ISO 14064, GHG Protocol (land sector), SBTi FLAG
- Machinery/electronics: ISO 11783 (ISOBUS), ISO 25119 (functional safety for ag machinery software), ISO 18497 (highly automated ag machines), ISO 4254, ISO 13849
- Data: AgGateway ADAPT, ISOXML, agroXML, FAO AGROVOC, OGC standards
- Cyber: NIST CSF, IEC 62443, SOC 2

**Frameworks and platforms**
- Farm management: John Deere Operations Center, Climate FieldView, Trimble Ag, Granular
- Precision ag: RTK-GNSS guidance, variable-rate application, yield mapping, CAN/ISOBUS implements
- Remote sensing: Sentinel-2, Landsat, PlanetScope, NDVI, Google Earth Engine
- IoT: soil moisture probes, weather stations, LoRaWAN, NB-IoT, smart irrigation
- Carbon/MRV: Indigo, Regrow, Cool Farm Tool, COMET-Farm
- Traceability: GS1, blockchain pilots, lot tracking per FSMA 204 critical tracking events

**Dev stacks**
- Embedded: C/C++ and Rust on ESP32/STM32/nRF; FreeRTOS/Zephyr; CAN bus / J1939 / ISOBUS; GNSS/RTK; motor control; LoRa and solar power design
- Edge/robotics: ROS 2, PX4/ArduPilot for spraying and scouting drones, computer vision for weed detection (TensorFlow Lite, Jetson)
- Data/GIS: Python, PostGIS, GDAL, rasterio, QGIS, InfluxDB/TimescaleDB
- ML: yield prediction, disease detection, irrigation optimization (with explainability)
- Backend/mobile: Node/Python/Go, offline-first mobile, MQTT, REST/JSON

**Process and compliance**
- Records: field operations, inputs applied (pesticide logs with REI/PHI intervals), harvest lots, worker training
- Traceability: one-up/one-down lots, rapid recall (24-hour retrieval under FSMA 204)
- Audits: annual organic inspection, third-party food safety audits, conservation plan checks
- MRV for carbon claims: sampling protocols, uncertainty, additionality, permanence
- Functional safety: ISO 25119 performance levels (AgPL a to e)
- Data governance: farmer consent, portability, privacy in shared benchmarking

**Student-project feasibility**
- Strong. USDA, FDA, EPA, NRCS, ISO summaries, ADAPT, Sentinel data, QGIS, Earth Engine, and Cool Farm Tool are free.
- Embedded: smart irrigation controller (ESP32, soil moisture, valve actuation) with fail-safe valve states, sensor fault handling, water-use logging, ISO 25119-inspired risk analysis; modes (idle, irrigating, fault, manual override) form a natural state machine.
- Software: lot-traceability and spray-record system implementing FSMA 204 critical tracking events with audit logs and recall simulation.
- Limits: synthetic data; no carbon-credit or certification claims; ISO 25119 and 18497 are design guidance without an assessor.

**Key insight:** Sustainable farming GRC is driven by traceability and verifiable claims (organic, carbon, deforestation-free) more than device safety, with a real safety layer around automated machinery. It is one of the few fields where embedded sensors directly produce audit evidence.

---

### 17. Agriculture: Veterinary

**Regulations**
- FDA Center for Veterinary Medicine: animal drug approval (NADA/ANADA), Veterinary Feed Directive (21 CFR 558), AMDUCA (extralabel use), GFI #263 (medically important antimicrobials now Rx-only)
- Animal medical devices: FDA regulates but largely uses enforcement discretion; state rules vary
- USDA APHIS: Animal Health Protection Act, Animal Welfare Act, Center for Veterinary Biologics (9 CFR), Animal Disease Traceability (9 CFR 86), National Veterinary Accreditation Program, import/export health certificates
- DEA: Controlled Substances Act (ketamine, opioids, euthanasia drugs)
- State practice acts: licensure, VCPR (veterinarian-client-patient relationship, which gates telemedicine and prescribing), pharmacy rules
- Privacy: HIPAA does not apply to animal records, but state vet-confidentiality and client-data laws do
- Food safety link: FSIS inspection, residue testing, withdrawal periods
- Zoonotic/One Health: reportable animal diseases (NAHLN, WOAH list), CDC coordination, Select Agent rules
- International: WOAH Codes, EU Veterinary Medicinal Products Regulation 2019/6, Animal Health Law 2016/429, UK VMD, Codex MRLs

**Standards**
- ISO 11784/11785 (animal RFID), ISO 24631, ISO 15189/17025; AAVLD lab accreditation
- VICH guidelines (international veterinary drug harmonization)
- ISO 13485 for diagnostic devices, IEC 61010, IEC 60601 concepts for clinic equipment
- DICOM (vet radiology), HL7/FHIR adapters, SNOMED CT Veterinary Extension (VetSCT), AAHA accreditation standards
- Traceability: GS1, NAHLN messaging (HL7-based)
- Cyber: NIST CSF, ISO 27001, PCI DSS

**Frameworks and platforms**
- Practice management: Cornerstone/IDEXX, ezyVet, Covetrus Pulse, Shepherd, Digitail, AVImark
- Diagnostics: IDEXX, Zoetis, Antech integrations; analyzer interfaces (HL7/ASTM)
- Imaging: DICOM viewers/PACS
- Telemedicine: VCPR-compliant video platforms, remote monitoring
- Livestock health: DairyComp, Afimilk, RFID/EID tagging, milk and activity sensors
- Surveillance: NAHLN, WOAH-WAHIS, ProMED, APHIS dashboards
- Pharmacy/supply: e-prescribing, controlled-substance logs, vaccine cold chain

**Dev stacks**
- Enterprise: C#/.NET, Java, TypeScript/React, PostgreSQL, HL7/FHIR interfaces, SOC 2-style controls
- Embedded: wearables and collars (BLE/LoRa/cellular, IMU classification, low-power firmware), livestock bolus and ear-tag sensors, clinic devices (anesthesia monitors, infusion pumps, pulse oximetry, ECG), microchip scanners (ISO 11784/5), vaccine cold-chain loggers
- ML: gait and behavior analysis, radiograph classification, early disease detection
- Data: InfluxDB/TimescaleDB, sensor fusion, edge inference (TFLite)

**Process and compliance**
- Drug handling: controlled-substance logbooks, dispensing records, withdrawal-period tracking for food animals, antimicrobial stewardship reporting
- VCPR documentation; Certificates of Veterinary Inspection and health certification
- Disease reporting to state vets and USDA; biosecurity and quarantine protocols
- Lab quality systems: validation, proficiency testing, chain of custody
- Device development: ISO 14971-style risk management for anything affecting welfare or food safety

**Student-project feasibility**
- Strong and less crowded than human healthcare. FDA CVM, USDA APHIS, WOAH codes, VICH, AAHA summaries, and ISO 11784/5 overviews are free.
- Embedded: livestock or pet activity collar (ESP32/nRF with IMU) with on-device behavior classification, low-power design, tamper-evident logs, false-alert risk analysis, and RFID/EID handling per ISO 11784/5 concepts.
- Software: withdrawal-period and drug-inventory tracker with controlled-substance logging and CVI export, or a disease-reporting pipeline with synthetic data and HL7-style messages.
- Limits: no real patient or client data; no diagnostic accuracy, device, or drug-approval claims.

**Key insight:** Veterinary GRC sits between healthcare and agriculture. Drug control, recordkeeping, and food-safety consequences (residues, withdrawal periods, disease traceability) carry the most regulatory weight, while device regulation is much lighter than in human medicine.

---

### 18. Agriculture: Food Safety

**Regulations**
- FSMA (FDA): Preventive Controls for Human Food (21 CFR 117, HARPC), Produce Safety (Part 112), Foreign Supplier Verification Program, Sanitary Transportation, Intentional Adulteration (Part 121), Food Traceability Rule (compliance date extended to mid-2028; verify)
- USDA FSIS: meat, poultry, and egg inspection acts; 9 CFR 417 (HACCP); Salmonella and Listeria frameworks
- FDA labeling and allergens: FALCPA, FASTER Act (sesame), 21 CFR 101
- Recalls and reporting: Reportable Food Registry, mandatory recall authority, FDA registration
- Seafood HACCP (21 CFR 123); dairy (Pasteurized Milk Ordinance); shell eggs (21 CFR 118)
- Retail/foodservice: FDA Food Code
- EU/global: Regulation (EC) 178/2002, 852/2004, 2073/2005, 2017/625; Codex Alimentarius; FSANZ; CFIA (SFCR)

**Standards**
- HACCP (Codex seven principles); GFSI-benchmarked schemes: SQF, BRCGS, FSSC 22000, IFS, GlobalG.A.P.
- ISO 22000, ISO/TS 22002, ISO 22005 (traceability), ISO 17025, ISO 16140
- GS1: GTIN, GLN, SSCC, EPCIS, GS1 Digital Link, FSMA 204 KDE/CTE alignment
- Sanitary design: 3-A, EHEDG, NSF/ANSI 2 and 3
- Equipment safety: ISO 12100, IEC 60204-1, ISO 13849
- Cyber/OT: IEC 62443, NIST CSF; food defense plans
- Methods: AOAC, ISO 6579 (Salmonella), ISO 11290 (Listeria)

**Frameworks and platforms**
- QMS/compliance: SafetyCulture, FoodLogiQ, SAP Food and Beverage, TraceGains
- Traceability: EPCIS events, IBM Food Trust, retailer supplier mandates, recall simulation
- Process control: SCADA/PLC/MES (Rockwell, Siemens), historians for CCP monitoring
- Sensors: temperature loggers, metal detectors, X-ray inspection, checkweighers, pH/aw meters, ATP swabs, hyperspectral/vision inspection
- Lab/LIMS: pathogen testing, environmental monitoring, whole-genome sequencing (GenomeTrakr, PulseNet)
- Cold chain: reefer telematics, warehouse monitoring, BLE/LoRa loggers

**Dev stacks**
- Enterprise: C#/.NET, Java, Python, TypeScript; ERP/MES integration; EPCIS 2.0 (JSON-LD/REST); EDI
- Industrial/embedded: PLC logic (IEC 61131-3), Modbus, OPC UA, MQTT, Sparkplug B; CCP monitoring nodes with calibration tracking and alarm latching; cold-chain sensors; machine vision (C++/OpenCV, edge accelerators)
- Data/ML: anomaly detection on process data, contamination prediction, foreign-object detection
- Integrity: append-only or hash-chained records for data integrity expectations

**Process and compliance**
- Hazard analysis and preventive controls (process, allergen, sanitation, supply chain)
- HACCP plan: hazard analysis, CCPs, critical limits, monitoring, corrective actions, verification, records
- Validation vs. verification; environmental monitoring; supplier approval and incoming inspection
- Recall readiness: mock recalls, lot genealogy, 24-hour record retrieval
- CAPA and deviation handling; PCQI training; record retention (generally 2 years)
- Audits: unannounced GFSI audits, FDA/FSIS inspections

**Student-project feasibility**
- Strong, with a very clean compliance structure. FDA FSMA rules and guidance, Codex HACCP, FSIS guidelines, GS1 EPCIS, and NACMCF guidelines are free; ISO 22000 and SQF are paywalled but widely summarized.
- Embedded: CCP temperature monitoring node (ESP32 or STM32 with thermocouple/RTD) with critical-limit alarms, calibration log, deviation and corrective-action state machine, tamper-evident storage, and a written HACCP plan.
- Software: EPCIS-based lot traceability and mock-recall tool implementing FSMA 204 CTEs/KDEs with audit logging and recall-time measurement.
- Limits: synthetic production data; no HACCP validation or GFSI certification claims.

**Key insight:** Food safety GRC is a clear, repeatable control framework (hazard, control, monitor, record, verify) that turns naturally into software and sensor evidence. The HACCP logic is essentially a state machine with documentation requirements.

---

### 19. Defense: Command and Control (C2)

Overlaps with Aviation: Defense on RMF, CMMC, and export control. This profile focuses on information assurance, interoperability, and decision accountability.

**Regulations and policy**
- Acquisition: DoDD 5000.01, DoDI 5000.02, DoDI 5000.87 (software acquisition pathway), DFARS, JCIDS requirements process (under reform; verify)
- Cyber/information: DoDI 8510.01 (RMF), DoDI 8500.01, CNSSP 22, CNSSI 1253, DFARS 252.204-7012, CMMC, DoD Zero Trust strategy
- Export/supply chain: ITAR/EAR, Section 889, NIST 800-161
- Autonomy/AI: DoDD 3000.09, DoD AI Ethical Principles, Responsible AI guidance
- Law of armed conflict and rules of engagement drive legal review and human-judgment requirements
- Data: DoD Data Strategy, DoDI 8320.02
- Alliances: NATO STANAGs, Federated Mission Networking, Five Eyes; CJADC2 drives multi-service interoperability

**Standards**
- Symbology/messaging: MIL-STD-2525D/E, APP-6, MIL-STD-6016 (Link 16), Link 22, VMF (MIL-STD-6017), USMTF, OTH-Gold, Cursor on Target (CoT)
- Interoperability/data: NIEM, JC3IEDM/MIP, NITF, STANAG 4586 and 4609, ASTERIX
- Open architectures: FACE, SOSA, MOSA, CMOSS, VICTORY, GVA (UK Def Stan 23-09)
- Middleware: DDS (OMG); OGC geospatial standards
- Simulation: HLA (IEEE 1516), DIS (IEEE 1278), C2SIM (SISO-STD-019)
- Security: NIST 800-53/171/162 (ABAC), DISA STIGs/SRGs and SCAP, Cloud SRG impact levels (IL2 to IL6), NSA CSfC, CNSA 2.0, FIPS 140-3, Common Criteria, ICD 503/705, cross-domain baselines
- Architecture: DoDAF/UAF, SysML; safety/human factors: MIL-STD-882E, MIL-STD-1472H

**Frameworks and platforms** (program names change often; verify)
- TAK (ATAK/WinTAK/TAK Server), Palantir-based platforms, Anduril Lattice, Army NGC2 efforts, fires/targeting systems, Link 16 terminals
- DevSecOps: Platform One, Iron Bank, Big Bang, DoD DevSecOps Reference Design, software factories
- Edge/comms: MANET radios, SATCOM, tactical edge nodes for DDIL (denied, disrupted, intermittent, limited) networks
- Sim/wargaming: game-engine synthetic environments (Unreal/Unity), constructive sims, digital twins

**Dev stacks**
- Backend: Java (TAK plugins), C++, Rust, Python, Go, Ada; Kafka, DDS (RTI Connext, Cyclone DDS), ZeroMQ, Protobuf
- Geo/UI: Esri, Cesium, QGIS, MapLibre; Android for tactical handhelds
- Embedded/edge: SDR (GNU Radio), FPGAs, RTOS (VxWorks, INTEGRITY), GPS/PNT with jamming resilience, PTP time sync, encrypted mesh radios, low-SWaP nodes
- Data patterns: CRDTs, store-and-forward, offline-first sync, priority queuing, graceful degradation
- Security: PKI/CAC auth, FIPS-validated crypto, HSMs, secure boot, ABAC policy engines

**Process and compliance**
- RMF to ATO, increasingly continuous ATO (cATO) tied to DevSecOps pipelines
- Interoperability certification (JITC), Information Support Plans
- DT/OT including test and evaluation of AI-enabled components
- Cross-domain and multi-level security: labeling, guards, need-to-know enforcement
- Decision accountability: immutable audit of who saw and decided what; human-in-the-loop controls
- Legal and ethics review of decision-support and autonomy features
- Resilience under cyber/EW degradation; supply chain (SBOMs, provenance); clearances, TEMPEST

**Student-project feasibility**
- Moderate and narrower than most. Public: MIL-STD-2525 and APP-6 symbology, CoT schema, open-source TAK (ATAK-CIV, TAK Server via tak.gov registration), DDS, STIGs/SCAP, NIST publications, HLA/DIS tooling, OGC standards.
- Civil-framed project: search-and-rescue situational awareness system with a LoRa/ESP32 mesh tracker feeding a CoT/2525-style map, offline-first sync under simulated DDIL, ABAC rules, hash-chained audit logs, STIG-style hardening, SBOM, and an RMF-style control mapping.
- Simulation: small wargame or logistics simulator using DIS/HLA concepts with deterministic replay and an audit trail.
- Limits: unclassified only; no ITAR-controlled technical data in public repos; avoid targeting, fire control, or weapons-related functions.

**Key insight:** C2 GRC is about interoperability, information assurance, and accountability for decisions. The distinctive problems are cross-domain security, operating when the network is degraded, and governing AI in decision support. Game-engine and simulation work has unusually direct overlap.

---

### 20. Automotive (Road Vehicles and Software-Defined Vehicles)

**Regulations**
- US: NHTSA FMVSS (49 CFR 571), Safety Act and TREAD Act (defects, recalls), Standing General Order 2021-01 (crash reporting for ADS/Level 2 ADAS), NHTSA cybersecurity best practices, EPA/CARB OBD-II and emissions, state AV permitting (e.g. California DMV/CPUC)
- Connected-vehicle supply chain: Commerce/BIS rule restricting certain foreign-linked vehicle software and hardware (finalized early 2025, phased model-year dates; verify)
- UNECE WP.29: R155 (cybersecurity management system), R156 (software update management system), R157 (ALKS), R79 (steering); R155/R156 required for new vehicles in the EU, Japan, Korea, and others
- EU: Type Approval Regulation 2018/858, General Safety Regulation 2019/2144 (mandates ADAS features), GDPR, Data Act, Euro 7
- Other: China GB standards, Japan MLIT

**Standards**
- Safety: ISO 26262 (ASIL A to D), ISO 21448 SOTIF, UL 4600 (autonomous safety cases), ISO/TS 5083
- Cybersecurity: ISO/SAE 21434 (TARA, lifecycle), TISAX/VDA ISA, Uptane (secure OTA)
- Process/quality: Automotive SPICE, IATF 16949, ISO 9001
- Software: AUTOSAR (Classic and Adaptive), MISRA C:2012 / C++:2023, CERT C
- Networks: CAN/CAN FD (ISO 11898), LIN, FlexRay, Automotive Ethernet, SOME/IP, UDS (ISO 14229), DoIP (ISO 13400), SAE J1939, SAE J3016 (autonomy levels)
- Hardware: AEC-Q100, ISO 16750, CISPR 25
- EV/V2X: ISO 15118 (Plug and Charge), SAE J2945, SCMS

**Frameworks and platforms**
- OS/middleware: AUTOSAR stacks (Vector MICROSAR, EB tresos), QNX, Automotive Grade Linux, Android Automotive, Zephyr, FreeRTOS/SafeRTOS, Eclipse SDV, COVESA VSS
- MCUs/SoCs: Infineon AURIX, NXP S32K/S32G, Renesas RH850/R-Car, STM32, NVIDIA DRIVE, Qualcomm Ride
- Autonomy: ROS 2, Autoware, Apollo, openpilot
- Simulation/test: CARLA (Unreal-based), SUMO, Simulink/TargetLink, dSPACE, Vector CANoe, hardware-in-the-loop rigs, fault injection
- Tooling: Polyspace, LDRA, VectorCAST, Jama/Codebeamer/Polarion, python-can, SocketCAN

**Dev stacks**
- ECU firmware: C (MISRA) and restricted C++, some Rust; RTOS schedulers; watchdogs; memory protection; signed bootloaders (MCUboot)
- Adaptive/central compute: C++14/17 on POSIX, SOME/IP services, hypervisors, containerized workloads
- Safety mechanisms: E2E protection (CRC plus counters), redundancy, plausibility checks, degraded modes and safe states
- ML/perception: PyTorch to embedded inference, with SOTIF evidence and scenario coverage
- Simulation: Unreal/Unity scenario generation, deterministic replay, digital twins

**Process and compliance**
- V-model lifecycle with bidirectional traceability
- Safety: HARA, safety goals, ASIL, functional and technical safety concepts, ASIL decomposition, FMEA/FTA/FMEDA, safety case, confirmation reviews
- Cybersecurity: TARA, cybersecurity goals and claims, verification, incident response and field monitoring (R155 requires ongoing monitoring)
- Tool confidence levels; Development Interface Agreements between OEMs and suppliers
- Homologation/type approval; recall and OTA update governance; SBOM management

**Student-project feasibility**
- Very strong. UNECE R155/R156 and NHTSA materials are free; CARLA, Autoware, Zephyr, and python-can are open source. ISO standards are paywalled but summaries are plentiful.
- Embedded: electronic throttle or brake-by-wire simulator over CAN with a HARA, safety goals, E2E-protected messages, watchdog, fault injection, and a degradation state machine (normal, degraded, safe state). ESP32-family chips include a CAN-compatible controller (TWAI), so cheap hardware works.
- Cybersecurity: ISO 21434-style TARA plus secure boot, signed OTA, and UDS security access, mapped to an R155 CSMS checklist.
- Simulation: CARLA scenario suite for SOTIF with coverage metrics.
- Limits: no ASIL certification claims (independent assessment required); bench or simulator only; never touch real vehicle safety systems.

**Key insight:** Automotive is the clearest full-stack GRC fit in this list. Safety (26262), cyber (21434/R155), and process (ASPICE) are each explicit, auditable, and in heavy hiring demand, and embedded and game-engine skills both apply.

---

## Part 3: Verify Before Citing

These items are date-sensitive or were flagged as uncertain. Check current sources before using them in coursework or applications.

| Item | Why it needs checking |
|---|---|
| FSMA 204 Food Traceability Rule compliance date | Extended to mid-2028 as of my information; could change again |
| WHO Pandemic Agreement and PABS annex | Adopted 2025; annex negotiation and ratification status was still moving |
| US WHO withdrawal status | Announced; confirm effective dates and IHR implications |
| PAHPA reauthorization | Had lapsed; check whether it has been renewed |
| CFATS authority | Lapsed in 2023; check whether it was restored or replaced |
| JCIDS requirements process | Under reform; process names and instructions may have changed |
| BIS connected-vehicle rule | Phased model-year compliance dates; check for amendments |
| Army NGC2, Palantir, Anduril, TAK program names | Defense program names and vendors change frequently |
| USDA climate and carbon programs | Policy has shifted across administrations |
| Part 108 (BVLOS drones) | Proposed/emerging rule; check final status |
| NFPA 470 and related consolidated standards | Confirm current editions before citing section numbers |
| Any ISO/IEC/NFPA edition year | Editions are revised; confirm the current edition |

**General caveat:** This document was written from general knowledge without live source verification. Treat it as a map of where to look, then confirm details in the primary source (regulation text, standard body, or agency guidance) before relying on them.
