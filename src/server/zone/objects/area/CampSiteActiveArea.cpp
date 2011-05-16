/*
 *	server/zone/objects/area/CampSiteActiveArea.cpp generated by engine3 IDL compiler 0.60
 */

#include "CampSiteActiveArea.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/area/events/CampDespawnEvent.h"


// Imported class dependencies

#include "server/zone/objects/cell/CellObject.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "system/io/ObjectOutputStream.h"

#include "server/zone/ZonePacketHandler.h"

#include "engine/service/DatagramServiceThread.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "engine/util/Facade.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Observable.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/service/Message.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/login/account/Account.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/chat/ChatManager.h"

#include "server/zone/managers/minigames/ForageManager.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "system/io/ObjectInputStream.h"

#include "engine/util/ObserverEventMap.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "engine/core/Task.h"

#include "server/zone/managers/guild/GuildManager.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/managers/city/CityManager.h"

#include "engine/util/Observer.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/ZoneHandler.h"

#include "server/zone/Zone.h"

#include "engine/core/ManagedObject.h"

#include "server/zone/ZoneProcessServer.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/managers/minigames/GamblingManager.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/managers/creature/CreatureTemplateManager.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "system/lang/Exception.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "system/lang/Time.h"

#include "server/zone/ZoneClientSession.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "system/net/Packet.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "system/net/SocketAddress.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/auction/AuctionManager.h"

#include "server/zone/managers/loot/LootManager.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "system/util/VectorMap.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/managers/stringid/StringIdManager.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "system/net/Socket.h"

#include "system/util/Vector.h"

/*
 *	CampSiteActiveAreaStub
 */

enum {RPC_NOTIFYENTER__SCENEOBJECT_ = 6};

CampSiteActiveArea::CampSiteActiveArea() : ActiveArea(DummyConstructorParameter::instance()) {
	CampSiteActiveAreaImplementation* _implementation = new CampSiteActiveAreaImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

CampSiteActiveArea::CampSiteActiveArea(DummyConstructorParameter* param) : ActiveArea(param) {
}

CampSiteActiveArea::~CampSiteActiveArea() {
}


void CampSiteActiveArea::notifyEnter(SceneObject* player) {
	CampSiteActiveAreaImplementation* _implementation = (CampSiteActiveAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYENTER__SCENEOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyEnter(player);
}

DistributedObjectServant* CampSiteActiveArea::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void CampSiteActiveArea::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<CampSiteActiveAreaImplementation*>(servant));
}

/*
 *	CampSiteActiveAreaImplementation
 */

CampSiteActiveAreaImplementation::CampSiteActiveAreaImplementation(DummyConstructorParameter* param) : ActiveAreaImplementation(param) {
	_initializeImplementation();
}


CampSiteActiveAreaImplementation::~CampSiteActiveAreaImplementation() {
}


void CampSiteActiveAreaImplementation::finalize() {
}

void CampSiteActiveAreaImplementation::_initializeImplementation() {
	_setClassHelper(CampSiteActiveAreaHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void CampSiteActiveAreaImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (CampSiteActiveArea*) stub;
	ActiveAreaImplementation::_setStub(stub);
}

DistributedObjectStub* CampSiteActiveAreaImplementation::_getStub() {
	return _this;
}

CampSiteActiveAreaImplementation::operator const CampSiteActiveArea*() {
	return _this;
}

Object* CampSiteActiveAreaImplementation::clone() {
	return dynamic_cast<Object*>(new CampSiteActiveAreaImplementation(*this));
}


void CampSiteActiveAreaImplementation::lock(bool doLock) {
}

void CampSiteActiveAreaImplementation::lock(ManagedObject* obj) {
}

void CampSiteActiveAreaImplementation::rlock(bool doLock) {
}

void CampSiteActiveAreaImplementation::wlock(bool doLock) {
}

void CampSiteActiveAreaImplementation::wlock(ManagedObject* obj) {
}

void CampSiteActiveAreaImplementation::unlock(bool doLock) {
}

void CampSiteActiveAreaImplementation::runlock(bool doLock) {
}

void CampSiteActiveAreaImplementation::_serializationHelperMethod() {
	ActiveAreaImplementation::_serializationHelperMethod();

	_setClassName("CampSiteActiveArea");

}

void CampSiteActiveAreaImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(CampSiteActiveAreaImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool CampSiteActiveAreaImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ActiveAreaImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "spawnedObject") {
		TypeInfo<ManagedReference<SceneObject* > >::parseFromBinaryStream(&spawnedObject, stream);
		return true;
	}

	if (_name == "currentXP") {
		TypeInfo<float >::parseFromBinaryStream(&currentXP, stream);
		return true;
	}

	if (_name == "campType") {
		TypeInfo<byte >::parseFromBinaryStream(&campType, stream);
		return true;
	}

	if (_name == "aggroMod") {
		TypeInfo<byte >::parseFromBinaryStream(&aggroMod, stream);
		return true;
	}

	if (_name == "areaRange") {
		TypeInfo<float >::parseFromBinaryStream(&areaRange, stream);
		return true;
	}

	if (_name == "campObjects") {
		TypeInfo<Vector<ManagedReference<SceneObject* > > >::parseFromBinaryStream(&campObjects, stream);
		return true;
	}

	if (_name == "visitors") {
		TypeInfo<CampVisitorList >::parseFromBinaryStream(&visitors, stream);
		return true;
	}

	if (_name == "abandoned") {
		TypeInfo<bool >::parseFromBinaryStream(&abandoned, stream);
		return true;
	}

	if (_name == "despawnEvent") {
		TypeInfo<CampDespawnEvent >::parseFromBinaryStream(&despawnEvent, stream);
		return true;
	}

	if (_name == "maxXP") {
		TypeInfo<int >::parseFromBinaryStream(&maxXP, stream);
		return true;
	}

	if (_name == "campModifier") {
		TypeInfo<byte >::parseFromBinaryStream(&campModifier, stream);
		return true;
	}

	if (_name == "duration") {
		TypeInfo<int >::parseFromBinaryStream(&duration, stream);
		return true;
	}

	if (_name == "campOwner") {
		TypeInfo<ManagedReference<PlayerCreature* > >::parseFromBinaryStream(&campOwner, stream);
		return true;
	}

	if (_name == "placementTime") {
		TypeInfo<Time >::parseFromBinaryStream(&placementTime, stream);
		return true;
	}


	return false;
}

void CampSiteActiveAreaImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = CampSiteActiveAreaImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int CampSiteActiveAreaImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "spawnedObject";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<SceneObject* > >::toBinaryStream(&spawnedObject, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "currentXP";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&currentXP, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "campType";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<byte >::toBinaryStream(&campType, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "aggroMod";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<byte >::toBinaryStream(&aggroMod, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "areaRange";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&areaRange, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "campObjects";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<Vector<ManagedReference<SceneObject* > > >::toBinaryStream(&campObjects, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "visitors";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<CampVisitorList >::toBinaryStream(&visitors, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "abandoned";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<bool >::toBinaryStream(&abandoned, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "despawnEvent";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<CampDespawnEvent >::toBinaryStream(&despawnEvent, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "maxXP";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&maxXP, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "campModifier";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<byte >::toBinaryStream(&campModifier, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "duration";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&duration, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "campOwner";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<PlayerCreature* > >::toBinaryStream(&campOwner, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "placementTime";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<Time >::toBinaryStream(&placementTime, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 14 + ActiveAreaImplementation::writeObjectMembers(stream);
}

CampSiteActiveAreaImplementation::CampSiteActiveAreaImplementation() {
	_initializeImplementation();
	// server/zone/objects/area/CampSiteActiveArea.idl():  		currentXP = 0;
	currentXP = 0;
	// server/zone/objects/area/CampSiteActiveArea.idl():  		campType = 0;
	campType = 0;
	// server/zone/objects/area/CampSiteActiveArea.idl():  		aggroMod = 0;
	aggroMod = 0;
	// server/zone/objects/area/CampSiteActiveArea.idl():  		areaRange = 0;
	areaRange = 0;
	// server/zone/objects/area/CampSiteActiveArea.idl():  		abandoned = false;
	abandoned = false;
	// server/zone/objects/area/CampSiteActiveArea.idl():  		maxXP = 0;
	maxXP = 0;
	// server/zone/objects/area/CampSiteActiveArea.idl():  		campModifier = 0;
	campModifier = 0;
	// server/zone/objects/area/CampSiteActiveArea.idl():  		duration = 0;
	duration = 0;
	// server/zone/objects/area/CampSiteActiveArea.idl():  		Logger.setLoggingName("CampsiteActiveArea");
	Logger::setLoggingName("CampsiteActiveArea");
}

void CampSiteActiveAreaImplementation::notifyEnter(SceneObject* player) {
	// server/zone/objects/area/CampSiteActiveArea.idl():  	}
	if (!player->isPlayerCreature())	// server/zone/objects/area/CampSiteActiveArea.idl():  			return;
	return;
}

/*
 *	CampSiteActiveAreaAdapter
 */

CampSiteActiveAreaAdapter::CampSiteActiveAreaAdapter(CampSiteActiveAreaImplementation* obj) : ActiveAreaAdapter(obj) {
}

Packet* CampSiteActiveAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_NOTIFYENTER__SCENEOBJECT_:
		notifyEnter((SceneObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CampSiteActiveAreaAdapter::notifyEnter(SceneObject* player) {
	((CampSiteActiveAreaImplementation*) impl)->notifyEnter(player);
}

/*
 *	CampSiteActiveAreaHelper
 */

CampSiteActiveAreaHelper* CampSiteActiveAreaHelper::staticInitializer = CampSiteActiveAreaHelper::instance();

CampSiteActiveAreaHelper::CampSiteActiveAreaHelper() {
	className = "CampSiteActiveArea";

	Core::getObjectBroker()->registerClass(className, this);
}

void CampSiteActiveAreaHelper::finalizeHelper() {
	CampSiteActiveAreaHelper::finalize();
}

DistributedObject* CampSiteActiveAreaHelper::instantiateObject() {
	return new CampSiteActiveArea(DummyConstructorParameter::instance());
}

DistributedObjectServant* CampSiteActiveAreaHelper::instantiateServant() {
	return new CampSiteActiveAreaImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CampSiteActiveAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CampSiteActiveAreaAdapter((CampSiteActiveAreaImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

