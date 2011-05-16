/*
 *	server/zone/ZoneProcessServer.cpp generated by engine3 IDL compiler 0.60
 */

#include "ZoneProcessServer.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/chat/ChatManager.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/managers/vendor/VendorManager.h"


// Imported class dependencies

#include "server/zone/objects/cell/CellObject.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/managers/player/CharacterNameMap.h"

#include "engine/service/DatagramServiceThread.h"

#include "server/zone/objects/creature/professions/SkillBox.h"

#include "engine/util/Facade.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "engine/util/u3d/Quaternion.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/waypoint/WaypointObject.h"

#include "server/chat/StringIdChatParameterVector.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/chat/room/ChatRoomMap.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "server/chat/StringIdChatParameter.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "engine/core/Task.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/tangible/DamageMap.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/ZoneProcessServer.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/creature/SpeedMultiplierModChanges.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/chat/WaypointChatParameterVector.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "system/net/Packet.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/managers/objectcontroller/command/CommandConfigManager.h"

#include "server/zone/templates/tangible/SharedWeaponObjectTemplate.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "system/util/SortedVector.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/packets/MessageCallback.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/managers/player/PlayerMap.h"

#include "system/net/Socket.h"

#include "system/util/Vector.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "system/io/ObjectOutputStream.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "server/zone/objects/creature/commands/QueueCommand.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Observable.h"

#include "engine/service/Message.h"

#include "server/login/account/Account.h"

#include "server/chat/ChatManager.h"

#include "server/zone/managers/minigames/ForageManager.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/managers/player/StartingItemList.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/guild/GuildManager.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "engine/service/proto/BaseMessage.h"

#include "server/zone/packets/chat/ChatInstantMessageToCharacter.h"

#include "server/zone/ZoneHandler.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "engine/core/ManagedObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/managers/minigames/GamblingManager.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/managers/creature/CreatureTemplateManager.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "system/lang/Exception.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "system/lang/Time.h"

#include "server/zone/ZoneClientSession.h"

#include "engine/util/u3d/QuadTree.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/managers/objectcontroller/command/CommandList.h"

#include "system/net/SocketAddress.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/auction/AuctionManager.h"

#include "server/zone/managers/loot/LootManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/tangible/wearables/ArmorObject.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "system/util/VectorMap.h"

#include "server/zone/packets/chat/ChatRoomList.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/managers/player/StartingLocationList.h"

#include "server/zone/managers/stringid/StringIdManager.h"

#include "server/zone/objects/creature/buffs/Buff.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

/*
 *	ZoneProcessServerStub
 */

enum {RPC_INITIALIZE__ = 6,RPC_FINALIZE__,RPC_GETZONESERVER__,RPC_GETPLAYERMANAGER__,RPC_GETCHATMANAGER__,};

ZoneProcessServer::ZoneProcessServer(ZoneServer* server) : ManagedService(DummyConstructorParameter::instance()) {
	ZoneProcessServerImplementation* _implementation = new ZoneProcessServerImplementation(server);
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

ZoneProcessServer::ZoneProcessServer(DummyConstructorParameter* param) : ManagedService(param) {
}

ZoneProcessServer::~ZoneProcessServer() {
}


void ZoneProcessServer::initialize() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZE__);

		method.executeWithVoidReturn();
	} else
		_implementation->initialize();
}

VendorManager* ZoneProcessServer::getVendorManager() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getVendorManager();
}

ZoneServer* ZoneProcessServer::getZoneServer() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETZONESERVER__);

		return (ZoneServer*) method.executeWithObjectReturn();
	} else
		return _implementation->getZoneServer();
}

ZonePacketHandler* ZoneProcessServer::getPacketHandler() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getPacketHandler();
}

ProfessionManager* ZoneProcessServer::getProfessionManager() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getProfessionManager();
}

ObjectController* ZoneProcessServer::getObjectController() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getObjectController();
}

PlayerManager* ZoneProcessServer::getPlayerManager() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPLAYERMANAGER__);

		return (PlayerManager*) method.executeWithObjectReturn();
	} else
		return _implementation->getPlayerManager();
}

NameManager* ZoneProcessServer::getNameManager() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getNameManager();
}

HolocronManager* ZoneProcessServer::getHolocronManager() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getHolocronManager();
}

ChatManager* ZoneProcessServer::getChatManager() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCHATMANAGER__);

		return (ChatManager*) method.executeWithObjectReturn();
	} else
		return _implementation->getChatManager();
}

SuiManager* ZoneProcessServer::getSuiManager() {
	ZoneProcessServerImplementation* _implementation = (ZoneProcessServerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getSuiManager();
}

DistributedObjectServant* ZoneProcessServer::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void ZoneProcessServer::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<ZoneProcessServerImplementation*>(servant));
}

/*
 *	ZoneProcessServerImplementation
 */

ZoneProcessServerImplementation::ZoneProcessServerImplementation(DummyConstructorParameter* param) : ManagedServiceImplementation(param) {
	_initializeImplementation();
}


ZoneProcessServerImplementation::~ZoneProcessServerImplementation() {
	if (_this->isCurrentVersion(this))
	ZoneProcessServerImplementation::finalize();
}


void ZoneProcessServerImplementation::_initializeImplementation() {
	_setClassHelper(ZoneProcessServerHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void ZoneProcessServerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ZoneProcessServer*) stub;
	ManagedServiceImplementation::_setStub(stub);
}

DistributedObjectStub* ZoneProcessServerImplementation::_getStub() {
	return _this;
}

ZoneProcessServerImplementation::operator const ZoneProcessServer*() {
	return _this;
}

Object* ZoneProcessServerImplementation::clone() {
	return dynamic_cast<Object*>(new ZoneProcessServerImplementation(*this));
}


void ZoneProcessServerImplementation::lock(bool doLock) {
}

void ZoneProcessServerImplementation::lock(ManagedObject* obj) {
}

void ZoneProcessServerImplementation::rlock(bool doLock) {
}

void ZoneProcessServerImplementation::wlock(bool doLock) {
}

void ZoneProcessServerImplementation::wlock(ManagedObject* obj) {
}

void ZoneProcessServerImplementation::unlock(bool doLock) {
}

void ZoneProcessServerImplementation::runlock(bool doLock) {
}

void ZoneProcessServerImplementation::_serializationHelperMethod() {
	ManagedServiceImplementation::_serializationHelperMethod();

	_setClassName("ZoneProcessServer");

}

void ZoneProcessServerImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(ZoneProcessServerImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ZoneProcessServerImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedServiceImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void ZoneProcessServerImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ZoneProcessServerImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ZoneProcessServerImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + ManagedServiceImplementation::writeObjectMembers(stream);
}

VendorManager* ZoneProcessServerImplementation::getVendorManager() {
	// server/zone/ZoneProcessServer.idl():  		return vendorManager;
	return vendorManager;
}

ZoneServer* ZoneProcessServerImplementation::getZoneServer() {
	// server/zone/ZoneProcessServer.idl():  		return zoneServer;
	return zoneServer;
}

ZonePacketHandler* ZoneProcessServerImplementation::getPacketHandler() {
	// server/zone/ZoneProcessServer.idl():  		return zonePacketHandler;
	return zonePacketHandler;
}

ProfessionManager* ZoneProcessServerImplementation::getProfessionManager() {
	// server/zone/ZoneProcessServer.idl():  		return professionManager;
	return professionManager;
}

ObjectController* ZoneProcessServerImplementation::getObjectController() {
	// server/zone/ZoneProcessServer.idl():  		return objectController;
	return objectController;
}

PlayerManager* ZoneProcessServerImplementation::getPlayerManager() {
	// server/zone/ZoneProcessServer.idl():  		return zoneServer.getPlayerManager();
	return zoneServer->getPlayerManager();
}

NameManager* ZoneProcessServerImplementation::getNameManager() {
	// server/zone/ZoneProcessServer.idl():  		return nameManager;
	return nameManager;
}

HolocronManager* ZoneProcessServerImplementation::getHolocronManager() {
	// server/zone/ZoneProcessServer.idl():  		return holocronManager;
	return holocronManager;
}

ChatManager* ZoneProcessServerImplementation::getChatManager() {
	// server/zone/ZoneProcessServer.idl():  		return zoneServer.getChatManager();
	return zoneServer->getChatManager();
}

SuiManager* ZoneProcessServerImplementation::getSuiManager() {
	// server/zone/ZoneProcessServer.idl():  		return suiManager;
	return suiManager;
}

/*
 *	ZoneProcessServerAdapter
 */

ZoneProcessServerAdapter::ZoneProcessServerAdapter(ZoneProcessServerImplementation* obj) : ManagedServiceAdapter(obj) {
}

Packet* ZoneProcessServerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZE__:
		initialize();
		break;
	case RPC_FINALIZE__:
		finalize();
		break;
	case RPC_GETZONESERVER__:
		resp->insertLong(getZoneServer()->_getObjectID());
		break;
	case RPC_GETPLAYERMANAGER__:
		resp->insertLong(getPlayerManager()->_getObjectID());
		break;
	case RPC_GETCHATMANAGER__:
		resp->insertLong(getChatManager()->_getObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ZoneProcessServerAdapter::initialize() {
	((ZoneProcessServerImplementation*) impl)->initialize();
}

void ZoneProcessServerAdapter::finalize() {
	((ZoneProcessServerImplementation*) impl)->finalize();
}

ZoneServer* ZoneProcessServerAdapter::getZoneServer() {
	return ((ZoneProcessServerImplementation*) impl)->getZoneServer();
}

PlayerManager* ZoneProcessServerAdapter::getPlayerManager() {
	return ((ZoneProcessServerImplementation*) impl)->getPlayerManager();
}

ChatManager* ZoneProcessServerAdapter::getChatManager() {
	return ((ZoneProcessServerImplementation*) impl)->getChatManager();
}

/*
 *	ZoneProcessServerHelper
 */

ZoneProcessServerHelper* ZoneProcessServerHelper::staticInitializer = ZoneProcessServerHelper::instance();

ZoneProcessServerHelper::ZoneProcessServerHelper() {
	className = "ZoneProcessServer";

	Core::getObjectBroker()->registerClass(className, this);
}

void ZoneProcessServerHelper::finalizeHelper() {
	ZoneProcessServerHelper::finalize();
}

DistributedObject* ZoneProcessServerHelper::instantiateObject() {
	return new ZoneProcessServer(DummyConstructorParameter::instance());
}

DistributedObjectServant* ZoneProcessServerHelper::instantiateServant() {
	return new ZoneProcessServerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ZoneProcessServerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ZoneProcessServerAdapter((ZoneProcessServerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

