/*
 *	server/zone/objects/tangible/component/armor/ArmorComponent.cpp generated by engine3 IDL compiler 0.60
 */

#include "ArmorComponent.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"


// Imported class dependencies

#include "server/zone/objects/cell/CellObject.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "system/io/ObjectOutputStream.h"

#include "server/zone/ZonePacketHandler.h"

#include "engine/service/DatagramServiceThread.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "server/zone/objects/tangible/component/Component.h"

#include "engine/util/Facade.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Observable.h"

#include "engine/util/u3d/Quaternion.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

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

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

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

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

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

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "system/util/VectorMap.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

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
 *	ArmorComponentStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_UPDATECRAFTINGVALUES__MANUFACTURESCHEMATIC_};

ArmorComponent::ArmorComponent() : Component(DummyConstructorParameter::instance()) {
	ArmorComponentImplementation* _implementation = new ArmorComponentImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

ArmorComponent::ArmorComponent(DummyConstructorParameter* param) : Component(param) {
}

ArmorComponent::~ArmorComponent() {
}


void ArmorComponent::initializeTransientMembers() {
	ArmorComponentImplementation* _implementation = (ArmorComponentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void ArmorComponent::updateCraftingValues(ManufactureSchematic* schematic) {
	ArmorComponentImplementation* _implementation = (ArmorComponentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_UPDATECRAFTINGVALUES__MANUFACTURESCHEMATIC_);
		method.addObjectParameter(schematic);

		method.executeWithVoidReturn();
	} else
		_implementation->updateCraftingValues(schematic);
}

DistributedObjectServant* ArmorComponent::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void ArmorComponent::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<ArmorComponentImplementation*>(servant));
}

/*
 *	ArmorComponentImplementation
 */

ArmorComponentImplementation::ArmorComponentImplementation(DummyConstructorParameter* param) : ComponentImplementation(param) {
	_initializeImplementation();
}


ArmorComponentImplementation::~ArmorComponentImplementation() {
}


void ArmorComponentImplementation::finalize() {
}

void ArmorComponentImplementation::_initializeImplementation() {
	_setClassHelper(ArmorComponentHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void ArmorComponentImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ArmorComponent*) stub;
	ComponentImplementation::_setStub(stub);
}

DistributedObjectStub* ArmorComponentImplementation::_getStub() {
	return _this;
}

ArmorComponentImplementation::operator const ArmorComponent*() {
	return _this;
}

Object* ArmorComponentImplementation::clone() {
	return dynamic_cast<Object*>(new ArmorComponentImplementation(*this));
}


void ArmorComponentImplementation::lock(bool doLock) {
}

void ArmorComponentImplementation::lock(ManagedObject* obj) {
}

void ArmorComponentImplementation::rlock(bool doLock) {
}

void ArmorComponentImplementation::wlock(bool doLock) {
}

void ArmorComponentImplementation::wlock(ManagedObject* obj) {
}

void ArmorComponentImplementation::unlock(bool doLock) {
}

void ArmorComponentImplementation::runlock(bool doLock) {
}

void ArmorComponentImplementation::_serializationHelperMethod() {
	ComponentImplementation::_serializationHelperMethod();

	_setClassName("ArmorComponent");

}

void ArmorComponentImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(ArmorComponentImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ArmorComponentImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ComponentImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "specialResists") {
		TypeInfo<int >::parseFromBinaryStream(&specialResists, stream);
		return true;
	}


	return false;
}

void ArmorComponentImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ArmorComponentImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ArmorComponentImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "specialResists";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&specialResists, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + ComponentImplementation::writeObjectMembers(stream);
}

ArmorComponentImplementation::ArmorComponentImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/component/armor/ArmorComponent.idl():  		Logger.setLoggingName("ArmorComponent");
	Logger::setLoggingName("ArmorComponent");
	// server/zone/objects/tangible/component/armor/ArmorComponent.idl():  		specialResists = 0;
	specialResists = 0;
}

/*
 *	ArmorComponentAdapter
 */

ArmorComponentAdapter::ArmorComponentAdapter(ArmorComponentImplementation* obj) : ComponentAdapter(obj) {
}

Packet* ArmorComponentAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_UPDATECRAFTINGVALUES__MANUFACTURESCHEMATIC_:
		updateCraftingValues((ManufactureSchematic*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ArmorComponentAdapter::initializeTransientMembers() {
	((ArmorComponentImplementation*) impl)->initializeTransientMembers();
}

void ArmorComponentAdapter::updateCraftingValues(ManufactureSchematic* schematic) {
	((ArmorComponentImplementation*) impl)->updateCraftingValues(schematic);
}

/*
 *	ArmorComponentHelper
 */

ArmorComponentHelper* ArmorComponentHelper::staticInitializer = ArmorComponentHelper::instance();

ArmorComponentHelper::ArmorComponentHelper() {
	className = "ArmorComponent";

	Core::getObjectBroker()->registerClass(className, this);
}

void ArmorComponentHelper::finalizeHelper() {
	ArmorComponentHelper::finalize();
}

DistributedObject* ArmorComponentHelper::instantiateObject() {
	return new ArmorComponent(DummyConstructorParameter::instance());
}

DistributedObjectServant* ArmorComponentHelper::instantiateServant() {
	return new ArmorComponentImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ArmorComponentHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ArmorComponentAdapter((ArmorComponentImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

