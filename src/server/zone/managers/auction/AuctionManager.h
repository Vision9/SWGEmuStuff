/*
 *	server/zone/managers/auction/AuctionManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef AUCTIONMANAGER_H_
#define AUCTIONMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace managers {
namespace object {

class ObjectManager;

} // namespace object
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::object;

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionsMap;

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace vendor {

class VendorTerminal;

} // namespace vendor
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::vendor;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace vendor {
namespace bazaar {

class BazaarTerminal;

} // namespace bazaar
} // namespace vendor
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::vendor::bazaar;

namespace server {
namespace zone {
namespace objects {
namespace auction {

class AuctionItem;

} // namespace auction
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::auction;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

#include "server/zone/objects/auction/Vendor.h"

#include "server/zone/packets/auction/AuctionQueryHeadersResponseMessage.h"

#include "engine/log/Logger.h"

#include "engine/core/ManagedService.h"

#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionManager : public ManagedService {
public:
	static const int MAXPRICE = 20000;

	static const int MAXSALES = 20;

	static const int SALESFEE = 20;

	static const int CHECKEVERY = 2;

	AuctionManager(ZoneServer* server);

	void initialize();

	void checkVendorItems();

	void checkAuctions();

	void addSaleItem(PlayerCreature* player, unsigned long long objectid, Vendor* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	AuctionItem* createVendorItem(PlayerCreature* player, SceneObject* objectToSell, Vendor* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	int checkSaleItem(PlayerCreature* player, SceneObject* object, Vendor* vendor, int price);

	void getItemAttributes(PlayerCreature* player, unsigned long long objectid);

	void getData(PlayerCreature* player, int extent, unsigned long long vendorObjectID, int screen, unsigned int category, int count, int offset);

	void getLocalVendorData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset);

	void getGalaxyData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset);

	void getPlanetData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset);

	void getRegionData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset);

	int checkRetrieve(PlayerCreature* player, unsigned long long objectIdToRetrieve, Vendor* vendor);

	void retrieveItem(PlayerCreature* player, unsigned long long objectid, unsigned long long vendorID);

	void buyItem(PlayerCreature* player, unsigned long long objectid, int price1, int price2);

	void doAuctionBid(PlayerCreature* player, AuctionItem* item, int price1, int price2);

	void doInstantBuy(PlayerCreature* player, AuctionItem* item, int price1, int price2);

	int checkBidAuction(PlayerCreature* player, AuctionItem* item, int price1, int price2);

	void cancelItem(PlayerCreature* player, unsigned long long objectID);

	AuctionQueryHeadersResponseMessage* fillAuctionQueryHeadersResponseMessage(PlayerCreature* player, Vendor* vendor, VectorMap<unsigned long long, ManagedReference<AuctionItem* > >* items, int screen, unsigned int category, int count, int offset);

	AuctionsMap* getAuctionMap();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	AuctionManager(DummyConstructorParameter* param);

	virtual ~AuctionManager();

	friend class AuctionManagerHelper;
};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionManagerImplementation : public ManagedServiceImplementation, public Logger {
protected:
	ManagedReference<AuctionsMap* > auctionMap;

	ManagedWeakReference<ZoneServer* > zoneServer;

public:
	static const int MAXPRICE = 20000;

	static const int MAXSALES = 20;

	static const int SALESFEE = 20;

	static const int CHECKEVERY = 2;

	AuctionManagerImplementation(ZoneServer* server);

	AuctionManagerImplementation(DummyConstructorParameter* param);

	void initialize();

	void checkVendorItems();

	void checkAuctions();

	void addSaleItem(PlayerCreature* player, unsigned long long objectid, Vendor* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	AuctionItem* createVendorItem(PlayerCreature* player, SceneObject* objectToSell, Vendor* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium);

	int checkSaleItem(PlayerCreature* player, SceneObject* object, Vendor* vendor, int price);

	void getItemAttributes(PlayerCreature* player, unsigned long long objectid);

	void getData(PlayerCreature* player, int extent, unsigned long long vendorObjectID, int screen, unsigned int category, int count, int offset);

	void getLocalVendorData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset);

	void getGalaxyData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset);

	void getPlanetData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset);

	void getRegionData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset);

private:
	void refundAuction(AuctionItem* item);

public:
	int checkRetrieve(PlayerCreature* player, unsigned long long objectIdToRetrieve, Vendor* vendor);

	void retrieveItem(PlayerCreature* player, unsigned long long objectid, unsigned long long vendorID);

	void buyItem(PlayerCreature* player, unsigned long long objectid, int price1, int price2);

	void doAuctionBid(PlayerCreature* player, AuctionItem* item, int price1, int price2);

	void doInstantBuy(PlayerCreature* player, AuctionItem* item, int price1, int price2);

	int checkBidAuction(PlayerCreature* player, AuctionItem* item, int price1, int price2);

	void cancelItem(PlayerCreature* player, unsigned long long objectID);

	AuctionQueryHeadersResponseMessage* fillAuctionQueryHeadersResponseMessage(PlayerCreature* player, Vendor* vendor, VectorMap<unsigned long long, ManagedReference<AuctionItem* > >* items, int screen, unsigned int category, int count, int offset);

private:
	Vendor* getVendorFromObject(SceneObject* obj);

public:
	AuctionsMap* getAuctionMap();

	AuctionManager* _this;

	operator const AuctionManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~AuctionManagerImplementation();

	Object* clone();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class AuctionManager;
	friend class TransactionalObjectHandle<AuctionManagerImplementation*>;
};

class AuctionManagerAdapter : public ManagedServiceAdapter {
public:
	AuctionManagerAdapter(AuctionManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initialize();

	void checkVendorItems();

	void checkAuctions();

	void getItemAttributes(PlayerCreature* player, unsigned long long objectid);

	void getData(PlayerCreature* player, int extent, unsigned long long vendorObjectID, int screen, unsigned int category, int count, int offset);

	void retrieveItem(PlayerCreature* player, unsigned long long objectid, unsigned long long vendorID);

	void buyItem(PlayerCreature* player, unsigned long long objectid, int price1, int price2);

	void doAuctionBid(PlayerCreature* player, AuctionItem* item, int price1, int price2);

	void doInstantBuy(PlayerCreature* player, AuctionItem* item, int price1, int price2);

	int checkBidAuction(PlayerCreature* player, AuctionItem* item, int price1, int price2);

	void cancelItem(PlayerCreature* player, unsigned long long objectID);

	AuctionsMap* getAuctionMap();

};

class AuctionManagerHelper : public DistributedObjectClassHelper, public Singleton<AuctionManagerHelper> {
	static AuctionManagerHelper* staticInitializer;

public:
	AuctionManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<AuctionManagerHelper>;
};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

#endif /*AUCTIONMANAGER_H_*/
