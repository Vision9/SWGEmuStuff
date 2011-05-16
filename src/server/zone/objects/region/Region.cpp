/*
 *	server/zone/objects/region/Region.cpp generated by engine3 IDL compiler 0.60
 */

#include "Region.h"

#include "server/zone/objects/tangible/terminal/Terminal.h"

#include "server/zone/objects/tangible/terminal/vendor/bazaar/BazaarTerminal.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/shuttle/ShuttleCreature.h"

#include "server/zone/objects/building/city/CityHallObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/installation/shuttle/ShuttleInstallation.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/scene/SceneObject.h"


// Imported class dependencies

#include "server/zone/objects/region/Region.h"

#include "server/zone/objects/cell/CellObject.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/ZonePacketHandler.h"

#include "engine/service/DatagramServiceThread.h"

#include "server/zone/objects/creature/professions/SkillBox.h"

#include "engine/util/u3d/Coordinate.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "engine/util/u3d/Quaternion.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "server/chat/StringIdChatParameter.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "engine/core/Task.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/tangible/ticket/TicketObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/creature/SpeedMultiplierModChanges.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/objects/tangible/terminal/city/CityTerminal.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/creature/shuttle/ShuttleTakeOffEvent.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "system/net/Packet.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/objects/tangible/terminal/city/CityVoteTerminal.h"

#include "server/zone/templates/tangible/SharedWeaponObjectTemplate.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/objects/tangible/terminal/travel/TravelTerminal.h"

#include "system/util/SortedVector.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "system/net/Socket.h"

#include "system/util/Vector.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "system/io/ObjectOutputStream.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "server/zone/objects/creature/shuttle/ShuttleLandingEvent.h"

#include "engine/util/Observable.h"

#include "engine/service/Message.h"

#include "server/login/account/Account.h"

#include "server/zone/managers/minigames/ForageManager.h"

#include "server/chat/ChatManager.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "engine/util/ObserverEventMap.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/managers/guild/GuildManager.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "engine/util/Observer.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/ZoneHandler.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "engine/core/ManagedObject.h"

#include "server/zone/objects/creature/shuttle/ShuttleCreature.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/managers/minigames/GamblingManager.h"

#include "server/zone/managers/creature/CreatureTemplateManager.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "system/lang/Exception.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/ZoneClientSession.h"

#include "system/lang/Time.h"

#include "engine/util/u3d/QuadTree.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "system/net/SocketAddress.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/auction/AuctionManager.h"

#include "server/zone/managers/loot/LootManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/managers/stringid/StringIdManager.h"

#include "server/zone/objects/creature/buffs/Buff.h"

#include "server/zone/objects/tangible/terminal/ticketcollector/TicketCollector.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

/*
 *	RegionStub
 */

enum {RPC_NOTIFYENTER__SCENEOBJECT_ = 6,RPC_SENDGREETINGMESSAGE__PLAYERCREATURE_,RPC_SENDDEPARTINGMESSAGE__PLAYERCREATURE_,RPC_NOTIFYEXIT__SCENEOBJECT_,RPC_INSERTTOZONE__ZONE_,RPC_REMOVEFROMZONE__,RPC_DESPAWNCITYOBJECTS__,RPC_ADDBAZAAR__BAZAARTERMINAL_,RPC_GETBAZAAR__INT_,RPC_GETSHUTTLE__,RPC_GETBAZAARCOUNT__,RPC_ISREGION__,RPC_GETCITYHALL__,RPC_SETCITYHALL__CITYHALLOBJECT_};

Region::Region() : ActiveArea(DummyConstructorParameter::instance()) {
	RegionImplementation* _implementation = new RegionImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

Region::Region(DummyConstructorParameter* param) : ActiveArea(param) {
}

Region::~Region() {
}


void Region::notifyEnter(SceneObject* object) {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYENTER__SCENEOBJECT_);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyEnter(object);
}

void Region::sendGreetingMessage(PlayerCreature* player) {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDGREETINGMESSAGE__PLAYERCREATURE_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendGreetingMessage(player);
}

void Region::sendDepartingMessage(PlayerCreature* player) {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDDEPARTINGMESSAGE__PLAYERCREATURE_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendDepartingMessage(player);
}

void Region::notifyExit(SceneObject* object) {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYEXIT__SCENEOBJECT_);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyExit(object);
}

void Region::insertToZone(Zone* zone) {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INSERTTOZONE__ZONE_);
		method.addObjectParameter(zone);

		method.executeWithVoidReturn();
	} else
		_implementation->insertToZone(zone);
}

void Region::removeFromZone() {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REMOVEFROMZONE__);

		method.executeWithVoidReturn();
	} else
		_implementation->removeFromZone();
}

void Region::despawnCityObjects() {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DESPAWNCITYOBJECTS__);

		method.executeWithVoidReturn();
	} else
		_implementation->despawnCityObjects();
}

void Region::addBazaar(BazaarTerminal* ter) {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDBAZAAR__BAZAARTERMINAL_);
		method.addObjectParameter(ter);

		method.executeWithVoidReturn();
	} else
		_implementation->addBazaar(ter);
}

BazaarTerminal* Region::getBazaar(int idx) {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETBAZAAR__INT_);
		method.addSignedIntParameter(idx);

		return (BazaarTerminal*) method.executeWithObjectReturn();
	} else
		return _implementation->getBazaar(idx);
}

ShuttleInstallation* Region::getShuttle() {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSHUTTLE__);

		return (ShuttleInstallation*) method.executeWithObjectReturn();
	} else
		return _implementation->getShuttle();
}

int Region::getBazaarCount() {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETBAZAARCOUNT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getBazaarCount();
}

bool Region::isRegion() {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISREGION__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isRegion();
}

CityHallObject* Region::getCityHall() {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCITYHALL__);

		return (CityHallObject*) method.executeWithObjectReturn();
	} else
		return _implementation->getCityHall();
}

void Region::setCityHall(CityHallObject* hall) {
	RegionImplementation* _implementation = (RegionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETCITYHALL__CITYHALLOBJECT_);
		method.addObjectParameter(hall);

		method.executeWithVoidReturn();
	} else
		_implementation->setCityHall(hall);
}

DistributedObjectServant* Region::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void Region::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<RegionImplementation*>(servant));
}

/*
 *	RegionImplementation
 */

RegionImplementation::RegionImplementation(DummyConstructorParameter* param) : ActiveAreaImplementation(param) {
	_initializeImplementation();
}


RegionImplementation::~RegionImplementation() {
}


void RegionImplementation::finalize() {
}

void RegionImplementation::_initializeImplementation() {
	_setClassHelper(RegionHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void RegionImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Region*) stub;
	ActiveAreaImplementation::_setStub(stub);
}

DistributedObjectStub* RegionImplementation::_getStub() {
	return _this;
}

RegionImplementation::operator const Region*() {
	return _this;
}

Object* RegionImplementation::clone() {
	return dynamic_cast<Object*>(new RegionImplementation(*this));
}


void RegionImplementation::lock(bool doLock) {
}

void RegionImplementation::lock(ManagedObject* obj) {
}

void RegionImplementation::rlock(bool doLock) {
}

void RegionImplementation::wlock(bool doLock) {
}

void RegionImplementation::wlock(ManagedObject* obj) {
}

void RegionImplementation::unlock(bool doLock) {
}

void RegionImplementation::runlock(bool doLock) {
}

void RegionImplementation::_serializationHelperMethod() {
	ActiveAreaImplementation::_serializationHelperMethod();

	_setClassName("Region");

}

void RegionImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(RegionImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool RegionImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ActiveAreaImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "bazaars") {
		TypeInfo<VectorMap<unsigned long long, ManagedReference<BazaarTerminal* > > >::parseFromBinaryStream(&bazaars, stream);
		return true;
	}

	if (_name == "shuttleInstallation") {
		TypeInfo<ManagedReference<ShuttleInstallation* > >::parseFromBinaryStream(&shuttleInstallation, stream);
		return true;
	}

	if (_name == "cityHall") {
		TypeInfo<ManagedReference<CityHallObject* > >::parseFromBinaryStream(&cityHall, stream);
		return true;
	}


	return false;
}

void RegionImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = RegionImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int RegionImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "bazaars";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<VectorMap<unsigned long long, ManagedReference<BazaarTerminal* > > >::toBinaryStream(&bazaars, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "shuttleInstallation";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<ShuttleInstallation* > >::toBinaryStream(&shuttleInstallation, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "cityHall";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<CityHallObject* > >::toBinaryStream(&cityHall, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 3 + ActiveAreaImplementation::writeObjectMembers(stream);
}

RegionImplementation::RegionImplementation() : ActiveAreaImplementation() {
	_initializeImplementation();
	// server/zone/objects/region/Region.idl():  		bazaars.setNoDuplicateInsertPlan();
	(&bazaars)->setNoDuplicateInsertPlan();
	// server/zone/objects/region/Region.idl():  		bazaars.setNullValue(null);
	(&bazaars)->setNullValue(NULL);
}

void RegionImplementation::notifyEnter(SceneObject* object) {
	// server/zone/objects/region/Region.idl():  		if 
	if (object->isTerminal()){
	// server/zone/objects/region/Region.idl():  			Terminal term = (Terminal) object;
	Terminal* term = (Terminal*) object;
	// server/zone/objects/region/Region.idl():  		}
	if (term->isBazaarTerminal())	// server/zone/objects/region/Region.idl():  				bazaars.put(object.getObjectID(), (BazaarTerminal)object);
	(&bazaars)->put(object->getObjectID(), (BazaarTerminal*) object);
}
	// server/zone/objects/region/Region.idl():  		if 
	if (object->isPlayerCreature()){
	// server/zone/objects/region/Region.idl():  			sendGreetingMessage((PlayerCreature) object);
	sendGreetingMessage((PlayerCreature*) object);
}
	// server/zone/objects/region/Region.idl():  	}
	if (object->isShuttleInstallation()){
	// server/zone/objects/region/Region.idl():  			shuttleInstallation = (ShuttleInstallation) object;
	shuttleInstallation = (ShuttleInstallation*) object;
}
}

void RegionImplementation::notifyExit(SceneObject* object) {
	// server/zone/objects/region/Region.idl():  		if 
	if (object->isTerminal()){
	// server/zone/objects/region/Region.idl():  			Terminal term = (Terminal) object;
	Terminal* term = (Terminal*) object;
	// server/zone/objects/region/Region.idl():  		}
	if (term->isBazaarTerminal())	// server/zone/objects/region/Region.idl():  				bazaars.drop(object.getObjectID());
	(&bazaars)->drop(object->getObjectID());
}
	// server/zone/objects/region/Region.idl():  		if 
	if (object->isPlayerCreature()){
	// server/zone/objects/region/Region.idl():  			sendDepartingMessage((PlayerCreature) object);
	sendDepartingMessage((PlayerCreature*) object);
}
	// server/zone/objects/region/Region.idl():  	}
	if (object == shuttleInstallation){
	// server/zone/objects/region/Region.idl():  			shuttleInstallation = null;
	shuttleInstallation = NULL;
}
}

void RegionImplementation::removeFromZone() {
	// server/zone/objects/region/Region.idl():  		despawnCityObjects();
	despawnCityObjects();
	// server/zone/objects/region/Region.idl():  		super.removeFromZone();
	ActiveAreaImplementation::removeFromZone();
	// server/zone/objects/region/Region.idl():  		updateToDatabaseWithoutChildren();
	updateToDatabaseWithoutChildren();
}

void RegionImplementation::addBazaar(BazaarTerminal* ter) {
	// server/zone/objects/region/Region.idl():  		bazaars.put(ter.getObjectID(), ter);
	(&bazaars)->put(ter->getObjectID(), ter);
}

BazaarTerminal* RegionImplementation::getBazaar(int idx) {
	// server/zone/objects/region/Region.idl():  		return bazaars.get(idx);
	return (&bazaars)->get(idx);
}

ShuttleInstallation* RegionImplementation::getShuttle() {
	// server/zone/objects/region/Region.idl():  		return shuttleInstallation;
	return shuttleInstallation;
}

int RegionImplementation::getBazaarCount() {
	// server/zone/objects/region/Region.idl():  		return bazaars.size();
	return (&bazaars)->size();
}

bool RegionImplementation::isRegion() {
	// server/zone/objects/region/Region.idl():  		return true;
	return true;
}

CityHallObject* RegionImplementation::getCityHall() {
	// server/zone/objects/region/Region.idl():  		return cityHall;
	return cityHall;
}

void RegionImplementation::setCityHall(CityHallObject* hall) {
	// server/zone/objects/region/Region.idl():  		cityHall = hall;
	cityHall = hall;
}

/*
 *	RegionAdapter
 */

RegionAdapter::RegionAdapter(RegionImplementation* obj) : ActiveAreaAdapter(obj) {
}

Packet* RegionAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_NOTIFYENTER__SCENEOBJECT_:
		notifyEnter((SceneObject*) inv->getObjectParameter());
		break;
	case RPC_SENDGREETINGMESSAGE__PLAYERCREATURE_:
		sendGreetingMessage((PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_SENDDEPARTINGMESSAGE__PLAYERCREATURE_:
		sendDepartingMessage((PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_NOTIFYEXIT__SCENEOBJECT_:
		notifyExit((SceneObject*) inv->getObjectParameter());
		break;
	case RPC_INSERTTOZONE__ZONE_:
		insertToZone((Zone*) inv->getObjectParameter());
		break;
	case RPC_REMOVEFROMZONE__:
		removeFromZone();
		break;
	case RPC_DESPAWNCITYOBJECTS__:
		despawnCityObjects();
		break;
	case RPC_ADDBAZAAR__BAZAARTERMINAL_:
		addBazaar((BazaarTerminal*) inv->getObjectParameter());
		break;
	case RPC_GETBAZAAR__INT_:
		resp->insertLong(getBazaar(inv->getSignedIntParameter())->_getObjectID());
		break;
	case RPC_GETSHUTTLE__:
		resp->insertLong(getShuttle()->_getObjectID());
		break;
	case RPC_GETBAZAARCOUNT__:
		resp->insertSignedInt(getBazaarCount());
		break;
	case RPC_ISREGION__:
		resp->insertBoolean(isRegion());
		break;
	case RPC_GETCITYHALL__:
		resp->insertLong(getCityHall()->_getObjectID());
		break;
	case RPC_SETCITYHALL__CITYHALLOBJECT_:
		setCityHall((CityHallObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void RegionAdapter::notifyEnter(SceneObject* object) {
	((RegionImplementation*) impl)->notifyEnter(object);
}

void RegionAdapter::sendGreetingMessage(PlayerCreature* player) {
	((RegionImplementation*) impl)->sendGreetingMessage(player);
}

void RegionAdapter::sendDepartingMessage(PlayerCreature* player) {
	((RegionImplementation*) impl)->sendDepartingMessage(player);
}

void RegionAdapter::notifyExit(SceneObject* object) {
	((RegionImplementation*) impl)->notifyExit(object);
}

void RegionAdapter::insertToZone(Zone* zone) {
	((RegionImplementation*) impl)->insertToZone(zone);
}

void RegionAdapter::removeFromZone() {
	((RegionImplementation*) impl)->removeFromZone();
}

void RegionAdapter::despawnCityObjects() {
	((RegionImplementation*) impl)->despawnCityObjects();
}

void RegionAdapter::addBazaar(BazaarTerminal* ter) {
	((RegionImplementation*) impl)->addBazaar(ter);
}

BazaarTerminal* RegionAdapter::getBazaar(int idx) {
	return ((RegionImplementation*) impl)->getBazaar(idx);
}

ShuttleInstallation* RegionAdapter::getShuttle() {
	return ((RegionImplementation*) impl)->getShuttle();
}

int RegionAdapter::getBazaarCount() {
	return ((RegionImplementation*) impl)->getBazaarCount();
}

bool RegionAdapter::isRegion() {
	return ((RegionImplementation*) impl)->isRegion();
}

CityHallObject* RegionAdapter::getCityHall() {
	return ((RegionImplementation*) impl)->getCityHall();
}

void RegionAdapter::setCityHall(CityHallObject* hall) {
	((RegionImplementation*) impl)->setCityHall(hall);
}

/*
 *	RegionHelper
 */

RegionHelper* RegionHelper::staticInitializer = RegionHelper::instance();

RegionHelper::RegionHelper() {
	className = "Region";

	Core::getObjectBroker()->registerClass(className, this);
}

void RegionHelper::finalizeHelper() {
	RegionHelper::finalize();
}

DistributedObject* RegionHelper::instantiateObject() {
	return new Region(DummyConstructorParameter::instance());
}

DistributedObjectServant* RegionHelper::instantiateServant() {
	return new RegionImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* RegionHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RegionAdapter((RegionImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

