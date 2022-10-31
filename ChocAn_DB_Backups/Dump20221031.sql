CREATE DATABASE  IF NOT EXISTS `sbingham` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `sbingham`;
-- MySQL dump 10.13  Distrib 8.0.31, for Win64 (x86_64)
--
-- Host: db.cecs.pdx.edu    Database: sbingham
-- ------------------------------------------------------
-- Server version	8.0.31-0ubuntu0.20.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `member`
--

DROP TABLE IF EXISTS `member`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `member` (
  `id` int NOT NULL AUTO_INCREMENT,
  `member_number` varchar(9) NOT NULL,
  `member_name` varchar(25) NOT NULL,
  `member_street` varchar(25) DEFAULT NULL,
  `member_city` varchar(14) DEFAULT NULL,
  `member_state` varchar(2) DEFAULT NULL,
  `member_zip` varchar(5) DEFAULT NULL,
  `member_status` int DEFAULT '1',
  `isDeleted` int DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `member_number_UNIQUE` (`member_number`)
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `member`
--

LOCK TABLES `member` WRITE;
/*!40000 ALTER TABLE `member` DISABLE KEYS */;
INSERT INTO `member` VALUES (1,'0','DEFAULT',NULL,NULL,NULL,NULL,NULL,NULL),(2,'631375719','Bob Firstname','1234 Bob Street','Portland','OR','56723',1,0),(3,'113019749','Trevon Osborne','44 Glen Ridge Court','Neptune','NJ','07753',1,0),(4,'346774635','Yazmin Crane','9792 Pacific Dr.','Morristown','NJ','07960',1,0),(5,'998325854','Jacoby Case','881 Liberty St.','Ashburn','VA','20147',1,0),(6,'109791467','Heidy Baird','96 East George Dr.','Front Royal','VA','22630',1,0),(7,'293470757','Kate Mosley','9581 Hill Ave','Encino','CA','91316',1,0),(8,'123634868','Karlee Jenkins','325 River St','Chicopee','MA','01020',1,0),(9,'258539521','Norah Jennings','9 Tunnel Avenue','Livingston','NJ','07039',1,0),(10,'20704467','Raiden Brennan','28 Old Selby Drive','Brick','NJ','08723',1,0),(11,'141572844','Kyra Phelps','9726 Nicolls St','Waukesha','WI','53186',1,0),(12,'971970990','Jadyn Irwin','430 Lilac Court','Waterloo','IA','50701',1,0),(13,'586036780','Colby Vaughn','30 Sunbeam Rd','Dorchester Ctr','MA','02124',1,0),(14,'851087663','Madison Castillo','870 Carriage St','Huntley','IL','60142',1,0),(15,'952142597','Clare Arroyo','7833 North Anderson St','Niagara Falls','NY','14304',1,0),(16,'511262694','Marlee Banks','272 Wall Street','Garfield','NJ','07026',1,0),(17,'881140036','Melany Gallegos','715 Edgemont Rd','Coraopolis','PA','15108',1,0),(18,'691519584','Belinda Nash','955 Heritage Lane','Collierville','TN','38017',1,0),(19,'598208863','Johanna Carr','44 Union Court','Mchenry','IL','60050',1,0),(20,'492102148','Destinee Clark','877 Oak Street','Highland Park','IL','60035',1,0),(21,'247494893','Riya Osborne','77 Elm Court','Glendora','CA','91740',1,0),(22,'105473271','Peyton Farmer','61 East Grant St','Mokena','IL','60448',1,0),(23,'811643394','Tucker Dorsey','80 Franklin Drive','Queensbury','NY','12804',1,0),(24,'219617278','Dominik Robertson','925 Buckingham Drive','Memphis','TN','38106',1,0),(25,'670553897','Violet Kramer','56 Ivy Drive Suite 403','Loxahatchee','FL','33470',1,0),(26,'592236828','Muhammad Levy','469 Manchester Drive','Covington','GA','30014',1,0),(27,'259233630','Wayne Lawrence','73 Greenrose Drive','North Bergen','NJ','07047',1,0),(28,'753786716','Jordyn Cole','669 Aspen Street','Oswego','NY','13126',1,0),(29,'720543018','Maximillian Jacobson','470 Clinton Ave','Kingston','NY','12401',1,0),(30,'254582483','Gillian Walters','168 Monroe Ave','West Babylon','NY','11704',1,0),(31,'776014327','Daniel Zamora','9559 Lakeshore Street','Sun City','AZ','85351',1,0);
/*!40000 ALTER TABLE `member` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `provider`
--

DROP TABLE IF EXISTS `provider`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `provider` (
  `id` int NOT NULL AUTO_INCREMENT,
  `provider_number` varchar(9) NOT NULL,
  `provider_name` varchar(25) NOT NULL,
  `provider_street` varchar(25) DEFAULT NULL,
  `provider_city` varchar(14) DEFAULT NULL,
  `provider_state` varchar(2) DEFAULT NULL,
  `provider_zip` varchar(5) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `provider_number_UNIQUE` (`provider_number`)
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `provider`
--

LOCK TABLES `provider` WRITE;
/*!40000 ALTER TABLE `provider` DISABLE KEYS */;
INSERT INTO `provider` VALUES (1,'000000000','DEFAULT','DEFAULT ADDRESS','DEFAULT','NA','00000'),(2,'392132245','Joe Zimmerman','7856 Holo Way 3','Voyager','IN','74656'),(3,'649742910','Leonard McCoy','6598 Bonaview St','Enterprise ','EX','17013'),(4,'208735853','Julian Bashir','934 Dartera Blvd','Terok Nor','BA','41909'),(5,'266896573','Bev Crusher','1356 Candela Rd','Enterpise','GA','17014'),(6,'607737794','Kathy Pulaski','6538 Shadowgrey St','Enterprise ','GA','17014'),(7,'299100464','Denny Phlox','24 Porthos Lane','Nexowan','PR','14241'),(8,'828979325','Joe M\'Benga','2248 Rukiya Dr','Enterprise ','CO','17012'),(9,'572327312','Gillian T\'Ana','2380 Alonquin Way','Cerritos','CA','75567'),(10,'445305351','Angus Zero','8423 Medusa St','Protostar','PR','76884'),(11,'158452334','Bruce Maddox','9329 Daystrom Lane','Drumhead','EA','71968'),(12,'320269951','Tracy Pollard','38 Background St','Discovery','CF','10314'),(13,'419147935','Hugh Culber','52 Mycellum Way','Discovery','CF','10314'),(14,'558360642','Emil Rios','1927 Multiplicity Rd','La Sirena','KA','93131'),(15,'300678766','Bob Zimmerman','22 Mirror Street','Equinox','NO','72381'),(16,'958016958','Chrisy Chapel','3514 Barret Lane','Enterprise ','EX','17013'),(17,'988689498','Patty Tagana','284 Alexander St','Terok Nor','BA','41909'),(18,'574339733','Beth Cutler','46 Admira Lane','Nexowan','PR','14241'),(19,'304715107','Ann Jabara','652 Dominia Way','Terok Nor','BA','41909'),(20,'861273080','Kes Lien','4322 Fast Lane','Voyager','IN','74656'),(21,'572098965','Alyssa Ogawa','5467 Prophecy Rd','Enterprise','GA','17014'),(22,'976730575','Mike Martinez','4521 Background Ave','Enterprise','GA','17014'),(23,'481853859','Tom Paris','55 Delta Route 2','Voyager','IN','74656'),(24,'823677843','D\'vana Tendi','2234 Hall Way 1','Cerritos','CA','75567');
/*!40000 ALTER TABLE `provider` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `service`
--

DROP TABLE IF EXISTS `service`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `service` (
  `id` int NOT NULL AUTO_INCREMENT,
  `service_number` varchar(6) NOT NULL,
  `service_name` varchar(20) NOT NULL,
  `service_cost` decimal(5,2) DEFAULT NULL,
  `service_status` int DEFAULT '1',
  PRIMARY KEY (`id`),
  UNIQUE KEY `service_number_UNIQUE` (`service_number`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `service`
--

LOCK TABLES `service` WRITE;
/*!40000 ALTER TABLE `service` DISABLE KEYS */;
INSERT INTO `service` VALUES (1,'0','DEFAULT',0.00,0),(2,'598470','Dietician Consult',125.00,1),(3,'883948','Aerobics Exercise',114.99,1),(5,'536017','Yoga Class',56.78,1),(6,'328445','Strength Consult',139.45,1),(7,'761635','Guided Meditation',44.22,1),(8,'182066','Dream Interpretation',39.99,1),(9,'961368','Tarot Readings',39.99,1),(10,'064870','Light Walking',25.00,1),(11,'543495','Heavy Walking',35.00,1),(12,'012267','Friendship Time',9.89,1),(13,'901442','Castle Building',659.76,1),(14,'263520','Solitary Confinement',1.99,1),(15,'701483','Bug Meditation',86.45,1),(16,'915865','Slapping',0.99,1);
/*!40000 ALTER TABLE `service` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transaction`
--

DROP TABLE IF EXISTS `transaction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transaction` (
  `id` int NOT NULL AUTO_INCREMENT,
  `trans_date` date DEFAULT NULL,
  `trans_date_time` datetime DEFAULT NULL,
  `provider_id` int DEFAULT NULL,
  `service_id` int DEFAULT NULL,
  `member_id` int DEFAULT NULL,
  `payment_status` int DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction`
--

LOCK TABLES `transaction` WRITE;
/*!40000 ALTER TABLE `transaction` DISABLE KEYS */;
/*!40000 ALTER TABLE `transaction` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'sbingham'
--

--
-- Dumping routines for database 'sbingham'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-10-31  7:00:28
